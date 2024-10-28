/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:12 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/24 17:29:21 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	flood_fill(char **map, int y, int x, t_data *data)
{
	int	nb_cols;
	int	nb_rows;

	nb_cols = data->collect->line_size + 1;
	nb_rows = data->collect->map_nb_lines + 1;
	if (y < 0 || y >= nb_rows + 1 || x < 0 || x >= nb_cols + 1)
		return ;
	if (map[y][x] != ' ' && map[y][x] != '\0')
		return ;
	else
		map[y][x] = '9';
	flood_fill(map, y - 1, x, data);
	flood_fill(map, y + 1, x, data);
	flood_fill(map, y, x - 1, data);
	flood_fill(map, y, x + 1, data);
}

void	fill_with_walls(char **map, int nb_cols, int nb_rows)
{
	int	x;
	int	y;

	x = ((y = 0));
	while (map[y] && y < nb_rows)
	{
		x = 0;
		while (map[y][x] && x < nb_cols)
		{
			if (map[y][x] == '9')
				map[y][x] = '.';
			x++;
		}
		y++;
	}
}

int	verif_flood_fill(char **map, int nb_cols, int nb_rows)
{
	int	x;
	int	y;

	x = ((y = 0));
	while (map[y] && y < nb_rows)
	{
		x = 0;
		while (map[y][x] && x < nb_cols)
		{
			if (x - 1 > 0 && !check_positions_ff(map[y][x], map[y][x - 1]))
				return (error_map(4));
			if (x + 1 < nb_cols && !check_positions_ff(map[y][x], map[y][x
				+ 1]))
				return (error_map(4));
			if (y - 1 > 0 && !check_positions_ff(map[y][x], map[y - 1][x]))
				return (error_map(4));
			if (y + 1 < nb_rows && !check_positions_ff(map[y][x], map[y
					+ 1][x]))
				return (error_map(4));
			x++;
		}
		y++;
	}
	fill_with_walls(map, nb_cols, nb_rows);
	return (1);
}

int	launch_fill(char **map, t_data *data, int nb_cols, int nb_rows)
{
	int	x;
	int	y;

	x = ((y = 0));
	while (x < nb_cols + 2)
	{
		if (map[0][x] == '0' || map[0][x] == ' ' || map[0][x] == '\0'
			|| verif_player(map[0][x]))
			flood_fill(map, 0, x, data);
		if (map[nb_rows - 1][x] == '0' || map[nb_rows - 1][x] == ' '
			|| map[nb_rows - 1][x] == '\0' || verif_player(map[nb_rows - 1][x]))
			flood_fill(map, nb_rows - 1, x, data);
		x++;
	}
	while (y < nb_rows + 2)
	{
		if (map[y][0] == '0' || map[y][0] == ' ' || map[y][0] == '\0'
			|| verif_player(map[y][0]))
			flood_fill(map, y, 0, data);
		if (map[y][nb_cols - 1] == '0' || map[y][nb_cols - 1] == ' '
			|| map[y][nb_cols - 1] == '\0' || verif_player(map[y][nb_cols - 1]))
			flood_fill(map, y, nb_cols - 1, data);
		y++;
	}
	return (1);
}
