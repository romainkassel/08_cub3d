/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:48:50 by Avandeve          #+#    #+#             */
/*   Updated: 2024/05/21 14:19:57 by avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrim(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static	size_t	get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (ft_istrim(set, s1[start]))
		start++;
	return (start);
}

static	size_t	get_end(char const *s1, char const *set)
{
	size_t	end;

	if (!ft_strlen(s1))
		return (0);
	end = ft_strlen(s1) - 1;
	while (ft_istrim(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		i;
	char		*str_trim;

	if (ft_strlen(s1) == 0)
		return (ft_calloc(1, sizeof(char)));
	start = get_start(s1, set);
	if (start >= ft_strlen(s1) - 1)
		return (ft_calloc(1, sizeof(char)));
	end = get_end(s1, set);
	str_trim = ft_calloc(((end - start) + 2), sizeof(char));
	if (!str_trim)
		return (NULL);
	i = 0;
	while ((start + i) <= end)
	{
		str_trim[i] = s1[start + i];
		i++;
	}
	return (str_trim);
}

/*
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char const	*s1;
	char const	*set;
	char		*trim;

	s1 = argv[1];
	set = argv[2];
	if (argc != 3)
		return (1);
	trim = ft_strtrim(s1, set);
	printf("Initial string : %s\n", s1);
	printf("Trimmable charset : %s\n", set);
	printf("Trimmed string : %s\n", trim);
	free(trim);
	return (0);
}
*/
