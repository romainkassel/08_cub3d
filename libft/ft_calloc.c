/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avandeve <avandeve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:09:07 by Avandeve          #+#    #+#             */
/*   Updated: 2024/06/26 16:29:47 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	i = 0;
	if (nmemb >= SIZE_MAX / size || size >= SIZE_MAX || nmemb * size > SIZE_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		return (ptr);
	}
	byte_ptr = (unsigned char *)ptr;
	while (i < nmemb * size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int					*calloc_test;
	int					*ft_calloc_test;
	long unsigned int	i;
	size_t				array_size;
	size_t				nmemb;

	array_size = 5;
	nmemb = 5;
	i = 0;
	printf("Testing the real calloc\n");
	calloc_test = (int *)calloc(nmemb,array_size);
	if(!calloc_test)
		return (printf("Memory allocation failed"), 1);
	printf("Printing the array : ");
	while (i < nmemb)
	{
		printf("%d", calloc_test[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("Testing ft_calloc\n");
	ft_calloc_test = (int *)ft_calloc(nmemb, array_size);
	if(!ft_calloc_test)
		return (printf("Memory allocation failed"),1);
	printf("Printing the array : ");
	while (i < nmemb)
	{
		printf("%d", ft_calloc_test[i]);
		i++;
	}
	printf("\n");
	printf("Comparing the two arrays\n");
	if(memcmp(calloc_test, ft_calloc_test, nmemb * array_size) == 0)
		printf("The arrays are the same : OK \n");
	else
	{
		printf("The arrays are different : KO \n");
	}
	free(calloc_test);
	free(ft_calloc_test);
	return (0);
}
*/
