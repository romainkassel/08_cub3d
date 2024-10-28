/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_collect_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:49:43 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/24 15:09:03 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_free_maps(char **map, int count)
{
	int	i;

	i = 0;
	while (i < count && map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_texts(char **texts)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		free(texts[i]);
		i++;
	}
	free(texts);
}

// Function to free the rgb table allowed by ft_split
void	free_rgb(char **rgb)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (rgb[i])
			free(rgb[i]);
		i++;
	}
	free(rgb);
}
