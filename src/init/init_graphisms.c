/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphisms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:24:19 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 15:06:40 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_cub3d	*init_cub3d_struct(t_data *data)
{
	t_cub3d	*cub3d;

	cub3d = ft_calloc(sizeof(t_cub3d), 1);
	if (!cub3d)
		return (NULL);
	cub3d->pos_x = data->collect->pos_player_x + 0.5;
	cub3d->pos_y = data->collect->pos_player_y + 0.5;
	cub3d->map_x = (int)cub3d->pos_x;
	cub3d->map_y = (int)cub3d->pos_y;
	cub3d->ceiling_color = data->collect->color_c;
	cub3d->floor_color = data->collect->color_f;
	cub3d->main_img = NULL;
	cub3d->text_north = ft_lstnew_img_obj(data);
	cub3d->text_south = ft_lstnew_img_obj(data);
	cub3d->text_east = ft_lstnew_img_obj(data);
	cub3d->text_west = ft_lstnew_img_obj(data);
	cub3d->map = copy_map(data->collect->copy_map, cub3d->map, data, 1);
	cub3d->map_h = data->collect->map_real_lines;
	cub3d->map_w = data->collect->map_real_lsize;
	return (cub3d);
}

t_raycast	*init_raycast_struct(t_data *data)
{
	t_raycast	*raycast;

	(void)data;
	raycast = ft_calloc(sizeof(t_raycast), 1);
	if (!raycast)
		return (NULL);
	raycast->dir_x = data->collect->orient_x;
	raycast->dir_y = data->collect->orient_y;
	raycast->plane_x = data->collect->plane_x;
	raycast->plane_y = data->collect->plane_y;
	raycast->camera_x = 0;
	raycast->ray_dir_x = 0;
	raycast->ray_dir_y = 0;
	raycast->delta_dist_x = 0;
	raycast->delta_dist_y = 0;
	raycast->step_x = 0;
	raycast->step_y = 0;
	raycast->side_dist_x = 0;
	raycast->side_dist_y = 0;
	raycast->is_wall_found = NOT_FOUND_YET;
	raycast->wall_side = 0;
	raycast->perp_wall_dist = 0;
	raycast->mouse_x = SCREEN_W / 2;
	return (raycast);
}

t_column	*init_column_struct(t_data *data)
{
	t_column	*column;

	(void)data;
	column = ft_calloc(sizeof(t_column), 1);
	if (!column)
		return (NULL);
	column->line_height = 0;
	column->draw_start = 0;
	column->draw_start_out = 0;
	column->draw_end = 0;
	column->draw_end_out = 0;
	column->wall_x = 0;
	column->text_x_pos = 0;
	column->text_x_by_bpp = 0;
	column->screen_x_by_bpp = 0;
	column->text_y_start_pos = 0;
	column->text_y_start_pos_tmp = 0;
	column->text_scale = 0;
	column->text_addr_i = 0;
	column->main_img_addr_i = 0;
	return (column);
}

t_mlx	*init_mlx(t_data *data)
{
	t_mlx	*mlx;

	(void)data;
	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (NULL);
	(void)data;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (free(mlx), NULL);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, SCREEN_W, SCREEN_H, "cub3d");
	if (!mlx->mlx_win)
		return (free(mlx->mlx_ptr), free(mlx), NULL);
	return (mlx);
}

int	init_graphisms(t_data *data)
{
	data->cub3d = init_cub3d_struct(data);
	data->minimap = init_minimap_struct(data);
	data->raycast = init_raycast_struct(data);
	data->column = init_column_struct(data);
	if (!data->cub3d || !data->minimap || !data->raycast || !data->column)
		return (ft_putendl_fd("Memory allocation failed", 2), 0);
	data->mlx = init_mlx(data);
	if (!data->mlx)
		return (0);
	if (!init_texts(data, data->cub3d))
		return (0);
	init_main_img(data);
	return (1);
}
