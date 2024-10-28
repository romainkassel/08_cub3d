/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:35:17 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/26 14:21:59 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_map_vector(t_cub3d *cub3d)
{
	cub3d->map_x = (int)cub3d->pos_x;
	cub3d->map_y = (int)cub3d->pos_y;
	return ;
}

void	get_delta_dist(t_raycast *raycast)
{
	raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	return ;
}

void	get_ray_dir(t_raycast *raycast)
{
	raycast->ray_dir_x = raycast->dir_x + raycast->plane_x * raycast->camera_x;
	raycast->ray_dir_y = raycast->dir_y + raycast->plane_y * raycast->camera_x;
	return ;
}

void	get_camera_x(t_raycast *raycast, int screen_x)
{
	raycast->camera_x = ((2 * (screen_x / (double)SCREEN_W)) - 1);
	return ;
}

void	raycast_it(t_data *data)
{
	int	screen_x;

	screen_x = 0;
	while (screen_x < SCREEN_W)
	{
		get_camera_x(data->raycast, screen_x);
		get_ray_dir(data->raycast);
		get_delta_dist(data->raycast);
		get_map_vector(data->cub3d);
		get_step_and_side_dist_x(data);
		get_step_and_side_dist_y(data);
		find_wall(data, data->cub3d);
		get_ray_distance(data->raycast);
		get_line_height(data);
		get_column_pixel_range(data->column);
		get_wall_impact_coordinate_on_x(data);
		draw_ceiling_column(data, data->column, screen_x);
		draw_floor_column(data, data->column, screen_x);
		draw_wall_column(data, data->column, screen_x);
		screen_x++;
	}
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->mlx_win,
		data->cub3d->main_img->img, 0, 0);
	return ;
}
