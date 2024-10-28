/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:14:19 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/23 09:04:29 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	if (size < 1)
		return (len);
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*
#include <stddef.h>
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char    dst[8];
        const char      src[]="Bonjour";
        printf("Test de la vraie fonction strlcpy : \n");
	strlcpy(dst, src, 7);
        printf("La longueur de la chaine est : %zu\n", strlcpy(dst, src, 1));
        printf("Chaine source :");
        puts(src);
        printf(" \n");
        puts(dst);
        printf("  \n");

	char	dst2[8];
	const char	src2[]="Bonjour";
	printf("Test de la fonction ft_strlcpy : \n");
	ft_strlcpy(dst2, src2, 7);
	printf("La longueur de la chaine est : %zu\n", ft_strlcpy(dst2, src2,1));
	printf("Chaine source :");
	puts(src2);
	printf(" \n");
	puts(dst2);
	printf("  \n");
	return (0);
}
*/
