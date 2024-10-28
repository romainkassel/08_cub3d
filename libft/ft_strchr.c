/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:20:54 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/22 15:53:19 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("Resultat de strchr : %s\n", strchr(argv[1], 'c'));
		printf("Resultat de ft_strchr : %s\n", ft_strchr(argv[1], 'c'));
	}
	printf("\n");
	return (0);
}
*/
