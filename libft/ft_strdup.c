/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:32:21 by Avandeve          #+#    #+#             */
/*   Updated: 2024/05/21 12:50:19 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s) + 1;
	copy = (char *) malloc (len * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*
#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	main(int argc, char **argv)
{
	const char	*str_cpy;

	str_cpy = argv[1];
	if (argc != 2)
		return (1);
	printf("Testing the real strdup : ");
	printf("%s\n", strdup(str_cpy));
	printf("Testing ft_strdup : ");
	printf("%s\n", ft_strdup(str_cpy));
	return (0);
}
*/
