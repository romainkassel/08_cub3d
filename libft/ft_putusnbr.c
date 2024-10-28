/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:13:37 by avandeve          #+#    #+#             */
/*   Updated: 2024/05/27 12:09:57 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigits_unsigned(unsigned int nb)
{
	long	nbr;
	int		count;

	ft_putusnbr(nb);
	count = 0;
	nbr = (long)nb;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_putusnbr(unsigned int nb)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putusnbr(nb / 10);
		ft_putusnbr(nb % 10);
	}
}
