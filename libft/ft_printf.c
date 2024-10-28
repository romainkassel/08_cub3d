/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:37:54 by avandeve          #+#    #+#             */
/*   Updated: 2024/06/27 11:07:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinbase(char c)
{
	char	*base;
	int		i;

	i = 0;
	base = "csdiuxXp%";
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (-1);
}

int	check_format(va_list ap, const char c, int fd)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_fd(va_arg(ap, int), fd);
	else if (c == 'd' || c == 'i')
		count += ft_countdigits(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (c == 'u')
		count += ft_countdigits_unsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		count += ft_countdigits_hex(va_arg(ap, unsigned int), c);
	else if (c == 'X')
		count += ft_countdigits_hex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
		count += ft_countdigits_ptraddress(va_arg(ap, void *));
	else if (c == '%')
		count += ft_putchar_fd('%', fd);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format, int fd, ...)
{
	va_list	ap;
	int		i;
	int		return_value;

	i = 0;
	return_value = 0;
	if (!format)
		return (-1);
	va_start(ap, fd);
	while (format[i])
	{
		if (format[i] == '%')
		{
			while (!ft_isinbase(format[i + 1]))
				i++;
			return_value += check_format(ap, format[i + 1], fd);
			i++;
		}
		else
			return_value += ft_putchar_fd(format[i], fd);
		i++;
	}
	va_end(ap);
	return (return_value);
}

/*

#include <stdio.h>

int	main(void)
{
	printf("Mon printf : %d/n",ft_printf(" %s, %x, %p", "Hello", -42, 0));
	printf("printf : %d/n", printf(" %s, %x, %p", "Hello", -42, 0));
	return (0);
}
*/
