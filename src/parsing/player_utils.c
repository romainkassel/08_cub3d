/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelle <amelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:59:47 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/24 20:05:39 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_orientation(char c, t_data *data)
{
	if (c == 'N')
	{
		data->collect->orient_y = -1;
		data->collect->plane_x = 0.66;
	}
	if (c == 'S')
	{
		data->collect->orient_y = 1;
		data->collect->plane_x = -0.66;
	}
	if (c == 'E')
	{
		data->collect->orient_x = 1;
		data->collect->plane_y = 0.66;
	}
	if (c == 'W')
	{
		data->collect->orient_x = -1;
		data->collect->plane_y = -0.66;
	}
}

int	is_player(char c, t_data *data, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		data->collect->pos_player_x = j;
		data->collect->pos_player_y = i;
		get_orientation(c, data);
		return (1);
	}
	return (0);
}
