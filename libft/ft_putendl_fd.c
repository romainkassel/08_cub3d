/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:58:52 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/29 11:33:41 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
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
		ft_putendl_fd(str, 1);
	}
	return (0);
}
*/
