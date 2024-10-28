/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling_floor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:35:17 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/23 15:43:51 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pix_on_img(int screen_x, int start_y, t_cub3d *cub3d, int col)
{
	t_img_obj	*main_img;
	int			red;
	int			green;
	int			blue;

	main_img = cub3d->main_img;
	red = (col >> 16) & 0xFF;
	green = (col >> 8) & 0xFF;
	blue = col & 0xFF;
	main_img->addr[start_y * main_img->line_length
		+ screen_x * main_img->bpp / 8] = blue;
	main_img->addr[start_y * main_img->line_length
		+ screen_x * main_img->bpp / 8 + 1] = green;
	main_img->addr[start_y * main_img->line_length
		+ screen_x * main_img->bpp / 8 + 2] = red;
	return ;
}

void	draw_floor_column(t_data *data, t_column *column, int screen_x)
{
	int			start_y;
	int			end_y;

	start_y = SCREEN_H;
	end_y = column->draw_end;
	if (start_y <= SCREEN_H)
	{
		while (start_y >= end_y)
		{
			put_pix_on_img(screen_x, start_y--,
				data->cub3d, data->cub3d->floor_color);
		}
	}
	return ;
}

void	draw_ceiling_column(t_data *data, t_column *column, int screen_x)
{
	int	start_y;
	int	end_y;

	start_y = 0;
	end_y = column->draw_start;
	if (start_y >= 0)
	{
		while (start_y < end_y)
		{
			put_pix_on_img(screen_x, start_y++, data->cub3d,
				(int)data->cub3d->ceiling_color);
		}
	}
	return ;
}
