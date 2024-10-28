/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:36:29 by Avandeve          #+#    #+#             */
/*   Updated: 2024/06/12 14:13:45 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkspaces(char c)
{
	if ((c > 8 && c < 14) || (c == 32))
		return (1);
	return (0);
}

int	ft_checkdigits(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
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
	while (nptr[i] && (ft_checkdigits(nptr[i])))
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("Resultat avec atoi : %d\n", atoi((const char *)argv[1]));
	printf("Resultat avec ft_atoi : %d\n", atoi((const char *)argv[1]));
	return (0);
}
*/
