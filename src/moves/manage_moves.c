/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:32:09 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/24 17:26:44 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_up(t_data *data)
{
	t_raycast	*raycast;
	t_cub3d		*cub3d;

	raycast = data->raycast;
	cub3d = data->cub3d;
	if (cub3d->map[(int)(cub3d->pos_y)][(int)(cub3d->pos_x + ((raycast->dir_x
					* MOV_SPEED) * GAP_BEFORE_WALL_COLISION))] != '1')
		cub3d->pos_x += raycast->dir_x * MOV_SPEED;
	if (cub3d->map[(int)(cub3d->pos_y + ((raycast->dir_y * MOV_SPEED)
				* GAP_BEFORE_WALL_COLISION))][(int)(cub3d->pos_x)] != '1')
		cub3d->pos_y += raycast->dir_y * MOV_SPEED;
	return ;
}

void	move_down(t_data *data)
{
	t_raycast	*raycast;
	t_cub3d		*cub3d;

	raycast = data->raycast;
	cub3d = data->cub3d;
	if (cub3d->map[(int)(cub3d->pos_y)][(int)(cub3d->pos_x - ((raycast->dir_x
					* MOV_SPEED) * GAP_BEFORE_WALL_COLISION))] != '1')
		cub3d->pos_x -= raycast->dir_x * MOV_SPEED;
	if (cub3d->map[(int)(cub3d->pos_y - ((raycast->dir_y * MOV_SPEED)
				* GAP_BEFORE_WALL_COLISION))][(int)(cub3d->pos_x)] != '1')
		cub3d->pos_y -= raycast->dir_y * MOV_SPEED;
	return ;
}

void	move_left(t_data *data)
{
	t_raycast	*raycast;
	t_cub3d		*cub3d;

	raycast = data->raycast;
	cub3d = data->cub3d;
	if (cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x + (raycast->ray_dir_y
			* MOV_SPEED) * GAP_BEFORE_WALL_COLISION)] != '1')
		cub3d->pos_x += raycast->ray_dir_y * MOV_SPEED;
	if (cub3d->map[(int)(cub3d->pos_y - (raycast->ray_dir_x * MOV_SPEED)
			* GAP_BEFORE_WALL_COLISION)][(int)cub3d->pos_x] != '1')
		cub3d->pos_y -= raycast->ray_dir_x * MOV_SPEED;
	return ;
}

void	move_right(t_data *data)
{
	t_raycast	*raycast;
	t_cub3d		*cub3d;

	raycast = data->raycast;
	cub3d = data->cub3d;
	if (cub3d->map[(int)cub3d->pos_y][(int)(cub3d->pos_x - (raycast->ray_dir_y
			* MOV_SPEED) * GAP_BEFORE_WALL_COLISION)] != '1')
		cub3d->pos_x -= raycast->ray_dir_y * MOV_SPEED;
	if (cub3d->map[(int)(cub3d->pos_y + (raycast->ray_dir_x * MOV_SPEED)
			* GAP_BEFORE_WALL_COLISION)][(int)cub3d->pos_x] != '1')
		cub3d->pos_y += raycast->ray_dir_x * MOV_SPEED;
	return ;
}
