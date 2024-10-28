/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:35:03 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 12:24:38 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	check_positions_ff(char c, char to_compare)
{
	if ((c == '9' || c == ' ') && (to_compare == '0'
			|| verif_player(to_compare)))
		return (0);
	return (1);
}

char	**copy_map_ff(t_data *data, char **copy_map, int nb_lines,
		int line_size)
{
	int	i;
	int	j;

	i = ((j = 0));
	while (data->collect->map[i] && i < nb_lines)
	{
		j = 0;
		while (data->collect->map[i][j] && j < line_size)
		{
			copy_map[i + 1][j + 1] = data->collect->map[i][j];
			printf("%s", copy_map[i + 1]);
			j++;
		}
		i++;
	}
	return (copy_map);
}

char	**create_map_ff(t_data *data, int nb_lines, int line_size)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = ft_calloc(nb_lines + 3, sizeof(char *));
	if (!copy_map)
		return (NULL);
	while (i < nb_lines + 2)
	{
		copy_map[i] = ft_calloc(line_size + 3, sizeof(char));
		if (!copy_map[i])
			return (ft_free(copy_map, i), NULL);
		i++;
	}
	if (!copy_map_ff(data, copy_map, nb_lines, line_size))
		return (0);
	return (copy_map);
}
