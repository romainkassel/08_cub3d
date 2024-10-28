/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_testing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelle <amelle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:02:38 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/20 10:04:28 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_copy_map(char **map, int nb_rows)
{
	int	i;

	i = 0;
	while (map[i] && i < nb_rows)
	{
		printf("%s\n", map[i]);
		i++;
	}
}
