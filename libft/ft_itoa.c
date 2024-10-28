/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:15:54 by Avandeve          #+#    #+#             */
/*   Updated: 2024/07/04 13:57:09 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_nb_len(long nb)
{
	size_t	nb_len;

	nb_len = 0;
	if (nb < 0)
	{
		nb_len++;
		nb *= -1;
		check_nb_len(nb);
	}
	if (nb == 0)
		return (1);
	if (nb >= 0 && nb <= 9)
		nb_len++;
	else
	{
		while (nb > 0)
		{
			nb /= 10;
			nb_len++;
			check_nb_len(nb);
		}
	}
	return (nb_len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*result;
	size_t	len;

	nb = (long)n;
	len = check_nb_len(nb);
	result = (char *) malloc(sizeof(char) * len + 1);
	if (! result)
		return (NULL);
	result[len] = '\0';
	len--;
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		result[len] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <stddef.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*str;

// 	str = ft_itoa(1);
// 	printf("%ld characters : %s\n", check_nb_len(-215687), str);
// 	puts(str);
// 	return (0);
// }
