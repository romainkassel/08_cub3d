/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:32:09 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/25 10:56:31 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_player_offset(t_data *data, int y, int x)
{
	t_minimap	*minimap;
	t_cub3d		*cub3d;
	t_img_obj	*main_img;
	int			player_offset;

	minimap = data->minimap;
	cub3d = data->cub3d;
	main_img = cub3d->main_img;
	player_offset = ((minimap->start_y + (int)(minimap->tile_size
					* cub3d->pos_y) - (minimap->player_size / 2) + y)
			* main_img->line_length) + (int)(minimap->start_x
			+ (minimap->tile_size * cub3d->pos_x)
			- (minimap->player_size / 2) + x) * (main_img->bpp / 8);
	return (player_offset);
}

void	draw_player(t_data *data)
{
	int			offset;
	char		*dst;
	int			y;
	int			x;

	y = 0;
	while (y < data->minimap->player_size)
	{
		x = 0;
		while (x < data->minimap->player_size)
		{
			offset = get_player_offset(data, y, x);
			dst = data->cub3d->main_img->addr + offset;
			*(unsigned int *)dst = PLAYER_COLOR;
			x++;
		}
		y++;
	}
	return ;
}

void	draw_cell(t_data *data, int offset, int bd_color, int bg_color)
{
	t_img_obj	*main_img;
	char		*dst;
	int			y;
	int			x;

	main_img = data->cub3d->main_img;
	y = 0;
	while (y < data->minimap->tile_size)
	{
		x = 0;
		while (x < data->minimap->tile_size)
		{
			dst = main_img->addr + offset + (y * main_img->line_length)
				+ (x * (main_img->bpp / 8));
			if (y == 0 || y == (data->minimap->tile_size - 1) || x == 0
				|| x == (data->minimap->tile_size - 1))
				*(unsigned int *)dst = bd_color;
			else
				*(unsigned int *)dst = bg_color;
			x++;
		}
		y++;
	}
	return ;
}

int	get_cell_offset(t_data *data, int y, int x)
{
	t_minimap	*minimap;
	t_img_obj	*main_img;
	int			cell_offset;

	minimap = data->minimap;
	main_img = data->cub3d->main_img;
	cell_offset = ((minimap->start_y + (y * minimap->tile_size))
			* main_img->line_length) + ((minimap->start_x
				+ (x * minimap->tile_size)) * (main_img->bpp / 8));
	return (cell_offset);
}

void	draw_minimap(t_data *data)
{
	int			y;
	int			x;
	int			offset;

	y = 0;
	while (y < data->cub3d->map_h)
	{
		x = 0;
		while (x < data->cub3d->map_w)
		{
			offset = get_cell_offset(data, y, x);
			if (data->cub3d->map[y][x] == '1')
				draw_cell(data, offset, WALL_BD_COL, WALL_BG_COL);
			else if (data->cub3d->map[y][x] != '.')
				draw_cell(data, offset, EMPTY_CELL_BD_COL, EMPTY_CELL_BG_COL);
			x++;
		}
		y++;
	}
	draw_player(data);
	return ;
}
