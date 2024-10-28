/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:35:17 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/24 17:19:26 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_wall_impact_coordinate_on_x(t_data *data)
{
	t_raycast	*raycast;
	t_column	*column;
	t_cub3d		*cub3d;

	raycast = data->raycast;
	column = data->column;
	cub3d = data->cub3d;
	if (raycast->wall_side == VERTICAL_SIDE_X_WEST
		|| raycast->wall_side == VERTICAL_SIDE_X_EAST)
	{
		column->wall_x = cub3d->pos_y + raycast->perp_wall_dist
			* raycast->ray_dir_y;
	}
	else
	{
		column->wall_x = cub3d->pos_x + raycast->perp_wall_dist
			* raycast->ray_dir_x;
	}
	column->wall_x -= floor(column->wall_x);
	return ;
}

void	get_column_pixel_range(t_column *column)
{
	column->draw_start = -column->line_height / 2 + SCREEN_H / 2;
	if (column->draw_start < 0)
	{
		column->draw_start_out = column->draw_start;
		column->draw_start = 0;
	}
	column->draw_end = column->line_height / 2 + SCREEN_H / 2;
	if (column->draw_end > SCREEN_H)
	{
		column->draw_end_out = column->draw_end;
		column->draw_end = SCREEN_H;
	}
	return ;
}

void	get_line_height(t_data *data)
{
	t_raycast	*raycast;
	t_column	*column;

	raycast = data->raycast;
	column = data->column;
	column->line_height = (int)(SCREEN_H / raycast->perp_wall_dist);
	return ;
}

void	get_ray_distance(t_raycast *raycast)
{
	if (raycast->wall_side == VERTICAL_SIDE_X_WEST
		|| raycast->wall_side == VERTICAL_SIDE_X_EAST)
	{
		raycast->perp_wall_dist = (raycast->side_dist_x
				- raycast->delta_dist_x);
	}
	else
		raycast->perp_wall_dist = (raycast->side_dist_y
				- raycast->delta_dist_y);
	return ;
}
