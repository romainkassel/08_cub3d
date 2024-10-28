/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:31:15 by Avandeve          #+#    #+#             */
/*   Updated: 2024/03/28 14:44:06 by Avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stddef.h>
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*byte_dest;
	const unsigned char	*byte_src;

	if (dest == src || n == 0 || (!dest && !src))
		return (dest);
	byte_src = (const unsigned char *)src;
	byte_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		byte_dest[i] = byte_src[i];
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	
	printf("\n Test avec ft_memcpy\n");
	char dest[100] = "Start stop";
	printf("Chaine de base : %s\n", dest);
	//printf("Test 1 : %s\n", (char *)memset(dest, 'A', 100));
	printf("Test 1 : %s\n", (char *)ft_memcpy(dest, dest + 6, 0));
	char src[50];
	printf("Test 2 : %s\n", (char *)memset(src, 'B', 50));
	printf("Test 3 : %s\n", (char *)ft_memcpy(dest, src, 2));
	printf("\n Test avec le vrai memcpy \n");
	char dest2[100] = "Start stop";
	printf("Chaine de base : %s\n", dest2);
	printf("Test 1 : %s\n", (char *)memcpy(dest2, dest2 + 6, 0));
	//printf("Test 1 : %s\n", (char *)memset(dest2, 'A', 100));
	char src2[50];
	printf("Test 2 : %s\n", (char *)memset(src2, 'B', 50));
	printf("Test 3 : %s\n", (char *)memcpy(dest2, src2, 2));

	return(0);
}
*/
