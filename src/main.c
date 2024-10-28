/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 08:53:36 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/26 14:22:29 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_and_parse(char *filename, t_data *data)
{
	if (!data)
		return (ft_putendl_fd("Error\nMemory allocation failed", 2), 1);
	init_data(data);
	if (!parse_file(filename, data))
		return (0);
	if (!parse_map(data))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	char	*filename;
	t_data	*data;

	if (argc != 2)
		return ((error_file(1), 1));
	filename = argv[1];
	if (!extension_control(filename))
		return (1);
	data = calloc(1, sizeof(t_data));
	if (!init_and_parse(filename, data))
		return (free_data(data), 1);
	if (!init_graphisms(data))
		return (free_data(data), 1);
	init_minimap(data);
	raycast_it(data);
	mlx_hook(data->mlx->mlx_win, 17, (1L << 0), exit_safely, data);
	mlx_key_hook(data->mlx->mlx_win, manage_keys, data);
	mlx_loop(data->mlx->mlx_ptr);
	if (data)
		free_data(data);
	return (0);
}
