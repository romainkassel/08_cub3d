/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:35:17 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/26 14:15:35 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_text_y_start_pos(t_data *data)
{
	double	draw_start_out;

	draw_start_out = data->column->draw_start_out;
	data->column->draw_start_out = 0;
	if (draw_start_out < 0)
	{
		draw_start_out *= -1;
		data->column->text_y_start_pos = draw_start_out
			* data->column->text_scale;
	}
	else
		data->column->text_y_start_pos = 0;
}

void	get_text_x_pos(t_data *data)
{
	double	wall_x;
	int		wall_side;

	wall_x = data->column->wall_x;
	wall_side = data->raycast->wall_side;
	if (wall_side == VERTICAL_SIDE_X_EAST
		|| wall_side == HORIZONTAL_SIDE_Y_NORTH)
	{
		data->column->text_x_pos = TEXTURE_SIZE - (wall_x * TEXTURE_SIZE);
	}
	else
		data->column->text_x_pos = wall_x * TEXTURE_SIZE;
}

void	get_column_var_values(t_data *data, int screen_x, t_img_obj *text)
{
	t_column	*column;
	t_img_obj	*main_img;

	column = data->column;
	main_img = data->cub3d->main_img;
	data->column->text_scale = (double)TEXTURE_SIZE
		/ (double)column->line_height;
	get_text_x_pos(data);
	get_text_y_start_pos(data);
	data->column->text_x_by_bpp = data->column->text_x_pos * text->bpp / 8;
	data->column->screen_x_by_bpp = screen_x * main_img->bpp / 8;
	return ;
}

// t_img_obj	*get_text(t_data *data)
// {
// 	t_img_obj	*text;
// 	t_cub3d		*cub3d;
// 	int			wall_side;

// 	wall_side = data->raycast->wall_side;
// 	cub3d = data->cub3d;
// 	if (wall_side == VERTICAL_SIDE_X_WEST)
// 		text = cub3d->text_west;
// 	else if (wall_side == HORIZONTAL_SIDE_Y_NORTH)
// 		text = cub3d->text_north;
// 	else if (wall_side == VERTICAL_SIDE_X_EAST)
// 		text = cub3d->text_east;
// 	else
// 		text = cub3d->text_south;
// 	return (text);
// }

t_img_obj	*get_text(t_data *data)
{
	t_img_obj	*text;
	t_cub3d		*cub3d;
	int			wall_side;

	wall_side = data->raycast->wall_side;
	cub3d = data->cub3d;
	if (wall_side == VERTICAL_SIDE_X_EAST)
		text = cub3d->text_east;
	else if (wall_side == HORIZONTAL_SIDE_Y_SOUTH)
		text = cub3d->text_south;
	else if (wall_side == VERTICAL_SIDE_X_WEST)
		text = cub3d->text_west;
	else
		text = cub3d->text_north;
	return (text);
}

void	draw_wall_column(t_data *data, t_column *column, int screen_x)
{
	double		start_y;
	double		end_y;
	t_img_obj	*text;

	text = get_text(data);
	get_column_var_values(data, screen_x, text);
	start_y = (double)column->draw_start;
	end_y = (double)column->draw_end;
	if (start_y >= 0 && end_y <= SCREEN_H)
	{
		data->column->text_y_start_pos_tmp = 0;
		while (start_y < end_y)
			put_text_on_main_img(data, start_y++, text);
	}
	return ;
}
