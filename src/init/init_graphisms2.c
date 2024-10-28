/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphisms2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:47:31 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 10:28:00 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img_obj	*ft_lstnew_window_object(t_data *data)
{
	t_img_obj	*window_object;

	(void)data;
	window_object = (t_img_obj *)ft_calloc(sizeof(t_img_obj), 1);
	if (!window_object)
		exit(EXIT_FAILURE);
	window_object->width = 0;
	window_object->height = 0;
	window_object->addr = 0;
	window_object->bpp = 0;
	window_object->endian = 0;
	window_object->img = 0;
	return (window_object);
}

t_minimap	*init_minimap_struct(t_data *data)
{
	t_minimap	*minimap;

	(void)data;
	minimap = ft_calloc(sizeof(t_minimap), 1);
	if (!minimap)
		return (NULL);
	minimap->tile_size = 0;
	minimap->minimap_w = 0;
	minimap->minimap_h = 0;
	minimap->start_x = 0;
	minimap->start_y = 0;
	minimap->player_size = 0;
	return (minimap);
}
