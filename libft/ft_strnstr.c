/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:27:06 by Avandeve          #+#    #+#             */
/*   Updated: 2024/05/20 13:25:08 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
#include <bsd/string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	const char	*str;
	const char	*to_find;
	size_t	n;

	str = argv[1];
	to_find = argv[2];
	n = atoi(argv[3]);
	if (argc != 4)
		return (1);
	printf("Test strnstr : %s\n", strnstr(str, to_find, n));
	printf("Test ft_strnstr : %s\n", ft_strnstr(str, to_find, n));
	return (0);
}
*/
