/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:16:38 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 16:17:56 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	count_player;

	i = ((j = 0));
	count_player = 0;
	while (map[i] && i < data->collect->map_nb_lines)
	{
		j = 0;
		if (data->collect->map_finished == 0 && ((!ft_strlen(map[i])
					|| (ft_strlen(map[i]) == 1 && map[i][0] == '\n'))))
			return (error_map(1), 0);
		while (map[i][j] && j < data->collect->line_size)
		{
			if (is_player(map[i][j], data, i, j))
				count_player++;
			else if (!is_a_map_char(map[i][j]))
				return (error_map(2), 0);
			j++;
		}
		i++;
	}
	if (count_player != 1)
		return (error_map(3), 0);
	return (1);
}

static int	get_real_line_size(char **map, t_data *data)
{
	int	i;
	int	j;
	int	count;

	data->collect->map_real_lsize = 0;
	i = 0;
	j = (int)ft_strlen(map[i]) - 1;
	while (map[i] && i < data->collect->map_real_lines)
	{
		j = (int)ft_strlen(map[i]) - 1;
		count = 0;
		while (j >= 0 && (map[i][j] == '.' || map[i][j] == '\n'
				|| map[i][j] == '\0'))
			j--;
		while (j > 0)
		{
			count++;
			j--;
		}
		i++;
		if (count > data->collect->map_real_lsize)
			data->collect->map_real_lsize = count;
	}
	return (data->collect->map_real_lsize);
}

static int	count_real_lines(char **map, t_data *data)
{
	int	i;
	int	j;
	int	count;
	int	valid_char;

	i = 0;
	count = 0;
	valid_char = 0;
	while (map[i] && i < data->collect->map_nb_lines)
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n' && j < data->collect->line_size)
		{
			if (map[i][j] != '.')
				valid_char = 1;
			j++;
		}
		i++;
		if (valid_char == 1)
			count++;
		valid_char = 0;
	}
	data->collect->map_real_lines = count;
	get_real_line_size(map, data);
	return (count);
}

char	**copy_map(char **map, char **copy_map, t_data *data, int index)
{
	int	i;
	int	j;
	int	len;
	int	nb_lines;

	i = ((j = 0));
	nb_lines = count_real_lines(map, data);
	len = data->collect->line_size;
	copy_map = malloc_map(nb_lines);
	if (!copy_map)
		return (ft_putendl_fd("Malloc error while copying map", 2), NULL);
	while (map[i + index] && i < nb_lines)
	{
		j = 0;
		copy_map[i] = ft_calloc(len + 1, sizeof(char));
		if (!copy_map[i])
			return ((void)ft_free(copy_map, i), NULL);
		while (map[i + index][j + index] && j < len)
		{
			copy_map[i][j] = map[i + index][j + index];
			j++;
		}
		i++;
	}
	return (copy_map);
}

int	parse_map(t_data *data)
{
	if (!verif_map(data->collect->map, data))
		return (0);
	data->collect->copy_map = create_map_ff(data, data->collect->map_nb_lines,
			data->collect->line_size);
	if (!data->collect->copy_map)
		return (0);
	if (!launch_fill(data->collect->copy_map, data, data->collect->line_size,
			data->collect->map_nb_lines))
		return (0);
	if (!verif_flood_fill(data->collect->copy_map, data->collect->line_size + 2,
			data->collect->map_nb_lines + 2))
		return (0);
	return (1);
}
