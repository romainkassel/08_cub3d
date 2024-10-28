/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:02:29 by avandeve          #+#    #+#             */
/*   Updated: 2024/10/22 14:51:08 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_atoi_cub(const char *nptr)
{
	long long	i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] && (ft_checkspaces(nptr[i])))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] != '\n')
	{
		if (!ft_checkdigits(nptr[i]))
			return (-1);
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

// Function to convert to hex
int	convert_to_hex(long r, long g, long b, int a)
{
	if (a < 0)
		a = 0;
	if (a > 255)
		a = 255;
	return ((a << 24) | (r << 16) | (g << 8) | b);
}
