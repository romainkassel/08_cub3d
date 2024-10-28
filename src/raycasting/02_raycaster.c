/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:35:17 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/26 11:48:31 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	manage_y_moves(t_data *data)
{
	t_cub3d		*cub3d;
	t_raycast	*raycast;

	cub3d = data->cub3d;
	raycast = data->raycast;
	raycast->side_dist_y += raycast->delta_dist_y;
	cub3d->map_y += raycast->step_y;
	if (cub3d->map_y > cub3d->pos_y)
		raycast->wall_side = HORIZONTAL_SIDE_Y_NORTH;
	else
		raycast->wall_side = HORIZONTAL_SIDE_Y_SOUTH;
	return ;
}

void	manage_x_moves(t_data *data)
{
	t_cub3d		*cub3d;
	t_raycast	*raycast;

	cub3d = data->cub3d;
	raycast = data->raycast;
	raycast->side_dist_x += raycast->delta_dist_x;
	cub3d->map_x += raycast->step_x;
	if (cub3d->map_x > cub3d->pos_x)
		raycast->wall_side = VERTICAL_SIDE_X_WEST;
	else
		raycast->wall_side = VERTICAL_SIDE_X_EAST;
	return ;
}

void	find_wall(t_data *data, t_cub3d *cub3d)
{
	t_raycast	*raycast;

	raycast = data->raycast;
	raycast->is_wall_found = NOT_FOUND_YET;
	while (raycast->is_wall_found == NOT_FOUND_YET)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
			manage_x_moves(data);
		else
			manage_y_moves(data);
		if (cub3d->map[cub3d->map_y][cub3d->map_x] == '1')
			raycast->is_wall_found = FOUND;
	}
	return ;
}

void	get_step_and_side_dist_y(t_data *data)
{
	t_raycast	*raycast;
	t_cub3d		*cub3d;

	cub3d = data->cub3d;
	raycast = data->raycast;
	if (raycast->ray_dir_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y = (cub3d->pos_y - cub3d->map_y)
			* raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (cub3d->map_y + 1.0 - cub3d->pos_y)
			* raycast->delta_dist_y;
	}
	return ;
}

void	get_step_and_side_dist_x(t_data *data)
{
	t_raycast	*raycast;
	t_cub3d		*cub3d;

	cub3d = data->cub3d;
	raycast = data->raycast;
	if (raycast->ray_dir_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x = (cub3d->pos_x - cub3d->map_x)
			* raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (cub3d->map_x + 1.0 - cub3d->pos_x)
			* raycast->delta_dist_x;
	}
	return ;
}
