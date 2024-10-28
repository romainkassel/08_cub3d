/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:42:31 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/23 13:22:26 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img_obj	*ft_lstnew_img_obj(t_data *data)
{
	t_img_obj	*window_object;

	(void)data;
	window_object = (t_img_obj *)ft_calloc(sizeof(t_img_obj), 1);
	if (!window_object)
	{
		free_data(data);
		exit(EXIT_FAILURE);
	}
	window_object->width = 0;
	window_object->height = 0;
	window_object->addr = 0;
	window_object->bpp = 0;
	window_object->endian = 0;
	window_object->img = 0;
	return (window_object);
}
