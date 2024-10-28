/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptraddress.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:14:00 by avandeve          #+#    #+#             */
/*   Updated: 2024/06/27 11:07:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigits_ptraddress(void *ptr)
{
	unsigned long	ptrl;
	int				count;

	if (ptr == 0)
		return (write(1, "(nil)", 5), 5);
	else
	{
		ptrl = (unsigned long)ptr;
		write(1, "0x", 2);
		ft_putptraddress(ptrl);
		count = 0;
		if (ptrl == 0)
			return (1);
		while (ptrl != 0)
		{
			ptrl /= 16;
			count++;
		}
		count += 2;
	}
	return (count);
}

void	ft_putptraddress(unsigned long ptrl)
{
	char	*hexbase;

	hexbase = "0123456789abcdef";
	if (ptrl < 16)
	{
		ft_putchar(hexbase[ptrl % 16]);
	}
	else if (ptrl >= 16)
	{
		ft_putptraddress(ptrl / 16);
		ft_putptraddress(ptrl % 16);
	}
}
