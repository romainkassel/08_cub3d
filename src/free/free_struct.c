/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:38:12 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 15:34:59 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_cub3d(t_data *data)
{
	if (data->cub3d)
	{
		if (data->cub3d->map)
			ft_free_maps(data->cub3d->map, data->collect->map_real_lines);
		destroy_images(data, data->cub3d);
		if (data->cub3d->main_img)
			free(data->cub3d->main_img);
		if (data->cub3d->text_north)
			free(data->cub3d->text_north);
		if (data->cub3d->text_south)
			free(data->cub3d->text_south);
		if (data->cub3d->text_east)
			free(data->cub3d->text_east);
		if (data->cub3d->text_west)
			free(data->cub3d->text_west);
		free(data->cub3d);
	}
}

void	free_collect(t_collect *collect)
{
	if (collect->map)
		ft_free_maps(collect->map, collect->map_nb_lines);
	if (collect->copy_map)
		ft_free_maps(collect->copy_map, collect->map_nb_lines + 2);
	if (collect->c_rgb)
		free_rgb(collect->c_rgb);
	if (collect->f_rgb)
		free_rgb(collect->f_rgb);
	if (collect->texts)
		ft_free_texts(collect->texts);
	free(collect);
	collect = NULL;
}

void	free_data(t_data *data)
{
	free_cub3d(data);
	if (data->minimap)
		free_minimap(data->minimap);
	if (data->column)
		free(data->column);
	if (data->raycast)
		free(data->raycast);
	if (data->collect)
		free_collect(data->collect);
	if (data->mlx)
		ft_free_mlx(data->mlx);
	free(data);
	data = NULL;
}
