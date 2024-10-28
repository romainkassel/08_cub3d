/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:32:09 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/24 17:25:24 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	manage_mouse(int x, int y, t_data *data)
{
	(void)y;
	if (x < data->raycast->mouse_x)
		rotate_camera_left(data, ROT_SPEED_MOUSE);
	else
		rotate_camera_right(data, ROT_SPEED_MOUSE);
	data->raycast->mouse_x = x;
	raycast_it(data);
	return (SUCCESS);
}

void	rotate_camera_left(t_data *data, double rot_speed)
{
	t_raycast	*raycast;
	double		olddir_x;
	double		oldplane_x;

	raycast = data->raycast;
	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(-rot_speed) - raycast->dir_y
		* sin(-rot_speed);
	raycast->dir_y = olddir_x * sin(-rot_speed) + raycast->dir_y
		* cos(-rot_speed);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(-rot_speed) - raycast->plane_y
		* sin(-rot_speed);
	raycast->plane_y = oldplane_x * sin(-rot_speed) + raycast->plane_y
		* cos(-rot_speed);
	return ;
}

void	rotate_camera_right(t_data *data, double rot_speed)
{
	t_raycast	*raycast;
	double		olddir_x;
	double		oldplane_x;

	raycast = data->raycast;
	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(rot_speed) - raycast->dir_y
		* sin(rot_speed);
	raycast->dir_y = olddir_x * sin(rot_speed) + raycast->dir_y
		* cos(rot_speed);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(rot_speed) - raycast->plane_y
		* sin(rot_speed);
	raycast->plane_y = oldplane_x * sin(rot_speed) + raycast->plane_y
		* cos(rot_speed);
	return ;
}
