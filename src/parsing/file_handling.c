/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:37 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/25 13:34:43 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Function to check if the .cub is actually a file and if access is granted
static bool	opening_test(char *str)
{
	int	fd;

	fd = open(str, __O_DIRECTORY);
	if (fd != -1)
		return (close(fd), error_file(3), false);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (perror(str), false);
	return (close(fd), true);
}

bool	extension_control(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = len - 1;
	if (!str)
		return (error_file(2), false);
	while (i >= len - 3)
	{
		if (str[i] != 'b')
			return (error_file(2), false);
		i--;
		if (str[i] != 'u')
			return (error_file(2), false);
		i--;
		if (str[i] != 'c')
			return (error_file(2), false);
		i--;
		if (str[i] != '.')
			return (error_file(2), false);
	}
	if (!opening_test(str))
		return (false);
	return (true);
}
