/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:07:22 by Avandeve          #+#    #+#             */
/*   Updated: 2024/05/21 16:26:37 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*final_str;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	final_str = ft_calloc(len, sizeof(char));
	if (!final_str)
		return (NULL);
	while (s[i])
	{
		final_str[i] = (*f)(i, s[i]);
		i++;
	}
	final_str[i] = '\0';
	return (final_str);
}

/*
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	ft_revalpha(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	else if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}


int	main(int argc, char **argv)
{
	char	*init_str;
	char	*final_str;

	if (argc != 2)
		return (printf("Missing argument!\n"), 1);
	else
	{
		init_str = argv[1];
		final_str = ft_strmapi(init_str, ft_revalpha);
		if (!final_str)
			printf("Memory allocation failed");
		printf("The initial string is : %s\n", init_str);
		printf("The strmapied string is : %s\n", final_str);
		free(final_str);
		return (0);
	}
}
*/
