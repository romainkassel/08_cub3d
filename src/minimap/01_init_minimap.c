/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_init_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:32:09 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/24 20:01:29 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_start_xy(t_minimap *minimap)
{
	minimap->start_x = SCREEN_W - minimap->minimap_w;
	minimap->start_y = SCREEN_H - minimap->minimap_h
		- MINIMAP_PADDING_TOP;
	return ;
}

void	get_minimap_size(t_data *data, t_cub3d *cub3d)
{
	data->minimap->minimap_w = data->minimap->tile_size * cub3d->map_w;
	data->minimap->minimap_h = data->minimap->tile_size * cub3d->map_h;
	return ;
}

void	get_player_size(t_data *data)
{
	data->minimap->player_size = data->minimap->tile_size / 2;
	return ;
}

void	get_tile_size(t_data *data)
{
	if (data->cub3d->map_w > data->cub3d->map_h)
		data->minimap->tile_size = MINIMAP_SIZE_MAX / data->cub3d->map_w;
	else
		data->minimap->tile_size = MINIMAP_SIZE_MAX / data->cub3d->map_h;
	return ;
}

void	init_minimap(t_data *data)
{
	get_tile_size(data);
	get_player_size(data);
	get_minimap_size(data, data->cub3d);
	get_start_xy(data->minimap);
	return ;
}
