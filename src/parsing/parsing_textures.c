/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:31:13 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/23 15:14:24 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Collecting texts and making sure they don't appear twice
int	check_text(char *line, char **text, int i)
{
	if (text[i] != 0)
		return (error_elements(3), 0);
	if (ft_strncmp("./", line, 2) && ft_strncmp("../", line, 2)
		&& ft_strncmp("~/", line, 2))
		return (ft_putstr_fd(line, 2), error_elements(4), 0);
	return (1);
}

static int	ft_strlen_text(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !(ft_checkspaces(line[i])))
		i++;
	return (i);
}

static int	which_texture(char *line)
{
	int	i;

	i = 0;
	if (!ft_strncmp(line, "NO ", 3))
		i = NO;
	if (!ft_strncmp(line, "SO ", 3))
		i = SO;
	if (!ft_strncmp(line, "EA ", 3))
		i = EA;
	if (!ft_strncmp(line, "WE ", 3))
		i = WE;
	return (i);
}

int	collect_texts(char *line, char **texture)
{
	int	i;
	int	j;
	int	len;
	int	k;

	i = ((j = 0));
	k = ((len = 0));
	while (line[k] && ft_checkspaces(line[k]))
		k++;
	i = which_texture(line + k);
	k += 3;
	while (line[k] && ft_checkspaces(line[k]))
		k++;
	if (!check_text(line + k, texture, i))
		return (0);
	len = ft_strlen_text(line + k) + 1;
	texture[i] = ft_calloc(len, sizeof(char));
	if (!texture[i])
		return (0);
	while (j < len - 1 && !ft_checkspaces(line[j + k]))
	{
		texture[i][j] = line[j + k];
		j++;
	}
	return (1);
}
