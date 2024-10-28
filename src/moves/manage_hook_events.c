/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_hook_events.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:32:09 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/25 11:10:56 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	manage_keys(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		exit_safely(data, SUCCESS);
	if (keycode == RIGHT_ARROW)
		rotate_camera_right(data, ROT_SPEED_ARROWS);
	else if (keycode == LEFT_ARROW)
		rotate_camera_left(data, ROT_SPEED_ARROWS);
	if (keycode == UP_W)
		move_up(data);
	else if (keycode == LEFT_A)
		move_left(data);
	else if (keycode == DOWN_S)
		move_down(data);
	else if (keycode == RIGHT_D)
		move_right(data);
	raycast_it(data);
	return (SUCCESS);
}
