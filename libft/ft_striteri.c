/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:25:27 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/29 11:30:40 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

void	ft_revalpha(unsigned int i, char *str)
{
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*init_str;

	if (argc != 2)
		return (printf("Missing argument!\n"), 1);
	else
	{
		init_str = argv[1];
		printf("The initial string is : %s\n", init_str);
		ft_striteri(init_str, ft_revalpha);
		printf("The striteri string is : %s\n", init_str);
		return (0);
	}
}
*/
