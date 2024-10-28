/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:17:04 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/26 15:25:45 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_text(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_checkspaces(line[i]))
		i++;
	if (!ft_strncmp(line + i, "NO ", 3) || !ft_strncmp(line + i, "SO ", 3)
		|| !ft_strncmp(line + i, "EA ", 3) || !ft_strncmp(line + i, "WE ", 3))
		return (true);
	return (false);
}

bool	is_f_or_c(char *line)
{
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		return (true);
	return (false);
}

bool	is_a_map_char(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == 'N' || c == 'W' || c == 'E'
		|| c == 'S')
		return (true);
	return (false);
}

bool	is_map(char *line)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = 0;
	while (line && i < len)
	{
		if (!is_a_map_char(line[i]) && line[i] != '\n' && line[i] != '\0')
			return (ft_putendl_fd("Error\nInvalid element", 2), printf("%s\n",
					line), false);
		i++;
	}
	return (true);
}
