/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:21:50 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/23 09:03:09 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*byte_s1;
	unsigned char	*byte_s2;
	size_t			i;

	i = 0;
	byte_s1 = (unsigned char *)s1;
	byte_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (byte_s1[i] != byte_s2[i])
			return (byte_s1[i] - byte_s2[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4) 
    {
        printf("Invalid arguments");
        return (1);
    }

    char *str1 = argv[1];
    char *str2 = argv[2];
    size_t n = atoi(argv[3]);
    int result1, result2;

    // Using ft_memcmp
    result1 = ft_memcmp(str1, str2, n);

    // Using memcmp
    result2 = memcmp(str1, str2, n);

    printf("Using ft_memcmp:\n");
    if (result1 == 0)
        printf("Returned value : %d\n", result1);
    else if (result1 < 0)
        printf("Returned value : %d\n", result1);
    else
        printf("Returned value : %d\n", result1);

    printf("\nUsing memcmp:\n");
    if (result2 == 0)
        printf("Returned value : %d\n", result2);
    else if (result2 < 0)
        printf("Returned value : %d\n", result2);
    else
        printf("Returned value : %d\n", result2);

    return (0);
}
*/
