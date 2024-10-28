/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:58:52 by Avandeve          #+#    #+#             */
/*   Updated: 2024/06/27 11:02:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s || !fd)
		return (write(fd, "(null)", 6));
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

/*
#include <unistd.h>
#include <stddef.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argc != 2)
		return (1);
	else
	{
		str = argv[1];
		ft_putstr_fd(str, 1);
	}
	return (0);
}
*/
