/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:53:11 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/26 15:26:14 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static bool	verify_all_elements(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->collect->texts[i] == 0)
			return (error_elements(1), false);
		i++;
	}
	if (!data->collect->color_c || !data->collect->color_f)
		return (error_elements(2), false);
	data->collect->all_elem_found = 1;
	return (true);
}

static int	handle_line(char *line, t_data *data, int j)
{
	(void)j;
	if (!line)
	{
		free_data(data);
		exit(1);
	}
	if (line[0] == '\n' && data->collect->map_found == 1)
	{
		free(line);
		return (1);
	}
	if (line[0] == '\n' && data->collect->file_nb_lines == 1)
	{
		free(line);
		error_elements(0);
		free_data(data);
		exit(1);
	}
	else if (line[0] == '\n')
	{
		free(line);
		return (1);
	}
	return (0);
}

static int	handle_map(char *line, int fd, int j, t_data *data)
{
	if (!is_map(line) || (!verify_all_elements(data) && is_map(line))
		|| (!is_map(line) && verify_all_elements(data)))
	{
		close(fd);
		free(line);
		free_data(data);
		exit(1);
	}
	if (is_map(line) && verify_all_elements(data))
	{
		data->collect->map_found = 1;
		return (collect_map(line, fd, j, data));
	}
	return (1);
}

int	collect_data_file(int fd, t_data *data)
{
	char	j;
	char	*line;

	j = 0;
	while (j++ < data->collect->file_nb_lines)
	{
		line = get_next_line(fd, data, j);
		if (handle_line(line, data, j))
			continue ;
		if (is_text(line))
		{
			if (!collect_texts(line, data->collect->texts))
				return (free(line), 0);
		}
		else if (is_f_or_c(line))
		{
			if (!collect_colors_fc(line, data))
				return (free(line), false);
		}
		else if (handle_map(line, fd, j, data))
			return (true);
		free(line);
	}
	return (true);
}

int	parse_file(char *filename, t_data *data)
{
	data->collect->fd = open(filename, O_RDONLY);
	if (data->collect->fd == -1)
		return (perror(filename), 0);
	if (!count_lines(data->collect->fd, data))
		return (close(data->collect->fd), 0);
	if (data->collect->file_nb_lines == 0)
		return (close(data->collect->fd), error_elements(0), 0);
	close(data->collect->fd);
	data->collect->fd = 0;
	data->collect->fd = open(filename, O_RDONLY);
	if (data->collect->fd == -1)
		return (perror(filename), 0);
	if (!collect_data_file(data->collect->fd, data))
		return (close(data->collect->fd), 0);
	if (!verify_all_elements(data))
		return (close(data->collect->fd), 0);
	if (!data->collect->map_found)
		return (close(data->collect->fd), error_map(6), 0);
	else
		close(data->collect->fd);
	return (1);
}
