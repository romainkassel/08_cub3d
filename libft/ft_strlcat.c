/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:16:08 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/22 15:50:06 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	j = 0;
	dest_len = ft_strlen((const char *)dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
	{
		return (size + src_len);
	}
	while (src[j] != '\0' && (dest_len + j < size -1))
	{
		dest[dest_len + j] = src[j];
		j++;
	}
	dest[dest_len + j] = '\0';
	return (dest_len + src_len);
}

/*
#include <stddef.h>
#include <bsd/string.h>
#include <stdio.h>
int	main(void)
{
	char	*src1;
	char	dest1[50] = "Hellooo";
	char    *src2;
        char    dest2[50] = "Hellooo";
	src1 = ", this is C";
	src2 = ", this is C";
	printf("Resultat ft_strlcat : %lu \n", ft_strlcat(dest1, src1, 8));
	printf("La chaine ft_strlcat : %s\n", dest1);
	printf("Resultat de la fonction strlcat : %lu\n", strlcat(dest2, src2, 8));
	printf("La chaine strlcat : %s\n", dest2);
	return (0);
}
*/
