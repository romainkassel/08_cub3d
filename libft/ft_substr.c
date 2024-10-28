/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:39:53 by Avandeve          #+#    #+#             */
/*   Updated: 2024/05/21 16:03:32 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	substr[0] = '\0';
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}

/*
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char const	*str;

	if (argc != 2)
		return (1);
	str = argv[1];
	printf("Initial string: %s\n", str);
	printf("Result of ft_substr : %s\n", ft_substr(str, 0, 5));
	return (0);
}
*/
