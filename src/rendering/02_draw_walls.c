/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_draw_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:35:17 by rkassel           #+#    #+#             */
/*   Updated: 2024/10/23 16:23:22 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_text_on_main_img(t_data *data, int start_y, t_img_obj *text)
{
	t_img_obj	*main_img;
	t_column	*column;
	int			main_img_addr_i;
	int			text_addr_i;

	main_img = data->cub3d->main_img;
	main_img_addr_i = data->column->main_img_addr_i;
	text_addr_i = data->column->text_addr_i;
	column = data->column;
	if ((int)column->text_y_start_pos != (int)column->text_y_start_pos_tmp)
		column->text_addr_i = (int)((int)column->text_y_start_pos
				* (double)text->line_length) + column->text_x_by_bpp;
	column->main_img_addr_i = start_y * main_img->line_length
		+ column->screen_x_by_bpp;
	if (start_y <= SCREEN_H)
	{
		main_img->addr[main_img_addr_i] = text->addr[text_addr_i];
		main_img->addr[main_img_addr_i + 1] = text->addr[text_addr_i + 1];
		main_img->addr[main_img_addr_i + 2] = text->addr[text_addr_i + 2];
	}
	column->text_y_start_pos_tmp = column->text_y_start_pos;
	column->text_y_start_pos += column->text_scale;
	return ;
}
