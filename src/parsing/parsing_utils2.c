/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:38:07 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 19:38:51 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_spaces(char *line, int fd, int j, t_data *data)
{
	int	i;

	i = 0;
	while (j < data->collect->file_nb_lines)
	{
		line = get_next_line(fd, data, j);
		i = 0;
		while (line[i] && i < (int)ft_strlen(line))
		{
			if (line[i] && !ft_checkspaces(line[i]))
			{
				free(line);
				error_map(7);
				close(fd);
				free_data(data);
				exit(1);
			}
			else
				i++;
		}
		if (line)
			free(line);
		j++;
	}
	return (1);
}
