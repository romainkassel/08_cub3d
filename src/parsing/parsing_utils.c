/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:25:18 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 11:41:24 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*ft_strjoin_cub(char const *s1, char const *s2, t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!str)
		return (free((char *)s1), free_data(data), NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	while (str[i + j++])
		str[i + j] = '\0';
	free((char *)s1);
	return (str);
}

static int	collect_lines(int len_line, t_data *data)
{
	data->collect->file_nb_lines += 1;
	if (len_line > data->collect->line_size)
		data->collect->line_size = len_line;
	return (0);
}

bool	count_lines(int fd, t_data *data)
{
	int		bytes_read;
	char	c;
	char	prev_c;
	int		len_line;

	len_line = 0;
	prev_c = '\0';
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, &c, 1);
		if (bytes_read == -1)
			return (error_file(4), false);
		if (bytes_read == 0)
			break ;
		if (is_a_map_char(c) == true)
			len_line++;
		if (c == '\n' || c == '\0')
			len_line = collect_lines(len_line, data);
		prev_c = c;
	}
	if (prev_c != '\n' && prev_c != '\0')
		collect_lines(len_line, data);
	return (true);
}

char	*get_next_line(int fd, t_data *data, int i)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;

	(void)i;
	line = NULL;
	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	bytes_read = 1;
	while ((bytes_read > 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		line = ft_strjoin_cub(line, buffer, data);
		if (!line)
			return (free_data(data), NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes_read == -1)
		return (free(line), free_data(data), NULL);
	return (line);
}

char	**malloc_map(int nb_lines)
{
	char	**copy_map;

	copy_map = ft_calloc(nb_lines + 1, sizeof(char *));
	if (!copy_map)
		return (NULL);
	return (copy_map);
}
