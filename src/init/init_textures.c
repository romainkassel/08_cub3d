/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:42:31 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/23 14:12:23 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img_obj	*init_texture(t_data *data, char *text_name, t_img_obj *text_str)
{
	text_str->img = mlx_xpm_file_to_image(data->mlx->mlx_ptr, text_name,
			&text_str->width, &text_str->height);
	if (!text_str->img)
		return (NULL);
	else
		text_str->addr = mlx_get_data_addr(text_str->img, &text_str->bpp,
				&text_str->line_length, &text_str->endian);
	return (text_str);
}

int	init_texts(t_data *data, t_cub3d *cub3d)
{
	if (!init_texture(data, data->collect->texts[NO], cub3d->text_north))
		return (perror(data->collect->texts[NO]), 0);
	if (!init_texture(data, data->collect->texts[SO], cub3d->text_south))
		return (perror(data->collect->texts[SO]), 0);
	if (!init_texture(data, data->collect->texts[WE], cub3d->text_west))
		return (perror(data->collect->texts[WE]), 0);
	if (!init_texture(data, data->collect->texts[EA], cub3d->text_east))
		return (perror(data->collect->texts[EA]), 0);
	return (1);
}
