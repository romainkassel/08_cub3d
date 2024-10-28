/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:31:02 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 14:32:21 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_collect	*init_collect(void)
{
	t_collect	*collect;

	collect = ft_calloc(sizeof(t_collect), 1);
	if (!collect)
		return (NULL);
	collect->fd = -2;
	collect->map = ((collect->copy_map = 0));
	collect->line_size = 0;
	collect->map_found = 0;
	collect->all_elem_found = 0;
	collect->lines_count = 0;
	collect->file_nb_lines = 0;
	collect->map_nb_lines = 0;
	collect->map_finished = 0;
	collect->texts = ft_calloc(5, sizeof(char *));
	collect->color_c = 0;
	collect->color_f = 0;
	collect->c_rgb = 0;
	collect->f_rgb = 0;
	collect->pos_player_x = -1;
	collect->pos_player_y = -1;
	collect->map_real_lines = ((collect->map_real_lsize = 0));
	collect->orient_x = ((collect->orient_y = 0));
	collect->plane_x = ((collect->plane_y = 0));
	return (collect);
}

t_data	*init_data(t_data *data)
{
	data->collect = init_collect();
	if (!data->collect)
		return (NULL);
	data->mlx = NULL;
	data->cub3d = NULL;
	data->minimap = NULL;
	data->column = NULL;
	data->raycast = NULL;
	return (data);
}
