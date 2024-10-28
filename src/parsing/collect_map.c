/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelle <amelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:30:13 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/26 08:51:12 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	malloc_collect_map(t_data *data, char *line, int j)
{
	data->collect->map_nb_lines = (data->collect->file_nb_lines - j) + 2;
	data->collect->map = ft_calloc(data->collect->map_nb_lines + 1,
			sizeof(char *));
	if (!data->collect->map)
	{
		free(line);
		free_data(data);
		exit(1);
	}
	data->collect->map_finished = 1;
	return (1);
}

int	collect_map(char *line, int fd, int j, t_data *data)
{
	int	k;
	int	l;

	k = ((l = 0));
	malloc_collect_map(data, line, j);
	while (k < data->collect->map_nb_lines)
	{
		data->collect->map[k] = ft_calloc(data->collect->line_size + 1,
				sizeof(char));
		if (!data->collect->map[k])
			return (ft_free(data->collect->map, k), free(line), 0);
		while (line[l] != '\n' && line[l] != '\0')
		{
			data->collect->map[k][l] = line[l];
			l++;
		}
		if (line)
			free(line);
		k++;
		l = 0;
		line = get_next_line(fd, data, j);
		if (line[0] == '\0' || line[0] == '\n')
			return (free(line), check_spaces(NULL, fd, j + k, data));
	}
	return (j);
}
