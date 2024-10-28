/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:39:37 by avandeve          #+#    #+#             */
/*   Updated: 2024/05/27 12:19:38 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned int nb, char c)
{
	char	*hexbaselow;
	char	*hexbaseup;

	hexbaselow = "0123456789abcdef";
	hexbaseup = "0123456789ABCDEF";
	if (nb < 16)
	{
		if (c == 'x')
			ft_putchar(hexbaselow[nb]);
		else if (c == 'X')
			ft_putchar(hexbaseup[nb]);
	}
	else if (nb >= 16)
	{
		ft_puthex(nb / 16, c);
		ft_puthex(nb % 16, c);
	}
}

int	ft_countdigits_hex(unsigned int nb, char c)
{
	int		count;

	count = 0;
	ft_puthex(nb, c);
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}
