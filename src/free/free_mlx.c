/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassel <rkassel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:19:55 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 11:03:54 by rkassel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	destroy_images(t_data *data, t_cub3d *cub3d)
{
	if (cub3d->main_img && cub3d->main_img->img)
		mlx_destroy_image(data->mlx->mlx_ptr, cub3d->main_img->img);
	if (cub3d->text_north && cub3d->text_north->img)
		mlx_destroy_image(data->mlx->mlx_ptr, cub3d->text_north->img);
	if (cub3d->text_south && cub3d->text_south->img)
		mlx_destroy_image(data->mlx->mlx_ptr, cub3d->text_south->img);
	if (cub3d->text_east && cub3d->text_east->img)
		mlx_destroy_image(data->mlx->mlx_ptr, cub3d->text_east->img);
	if (cub3d->text_west && cub3d->text_west->img)
		mlx_destroy_image(data->mlx->mlx_ptr, cub3d->text_west->img);
}

void	ft_free_mlx(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
}

void	free_minimap(t_minimap *minimap)
{
	if (minimap)
		free(minimap);
}
