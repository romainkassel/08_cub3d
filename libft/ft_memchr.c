/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:46:11 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/23 10:31:06 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*byte_s;
	unsigned char	byte_c;

	byte_s = (unsigned char *)s;
	byte_c = (unsigned char)c;
	while (n > 0)
	{
		if (*byte_s == byte_c)
			return ((void *)byte_s);
		byte_s++;
		n--;
	}
	return (NULL);
}

/*
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc != 4) 
    {
        printf("Usage: %s <string> <character>\n", argv[0]);
        return (1);
    }
    char *str = argv[1];
    char *result1, *result2;
    const char search_char = argv[2][0];
    size_t search_len = atoi(argv[3]);
    result1 = ft_memchr(str, search_char, search_len);
    result2 = memchr(str, search_char, search_len);
    printf("Using ft_memchr:\n");
    if (result1 != NULL)
    {
        printf("Character '%c'in position: %ld\n", search_char, result1 - str);
    	printf("The returned pointer is : %p\n", result1);
    }
    else
        printf("Character '%c' not found.\n", search_char);
    printf("\nUsing memchr:\n");
    if (result2 != NULL)
    {
	    printf("Character '%c' in position: %ld\n", search_char, result2 - str);
	    printf("The returned pointer is : %p\n", result2);
    }
    else
        printf("Character '%c' not found.\n", search_char);

    return (0);
}
*/
