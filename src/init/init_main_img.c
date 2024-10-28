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

void	init_main_img(t_data *data)
{
	t_img_obj	*main_img;

	data->cub3d->main_img = ft_lstnew_img_obj(data);
	main_img = data->cub3d->main_img;
	main_img->img = mlx_new_image(data->mlx->mlx_ptr, SCREEN_W, SCREEN_H);
	main_img->addr = mlx_get_data_addr(main_img->img, &main_img->bpp,
			&main_img->line_length, &main_img->endian);
	return ;
}
