/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:24:29 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/22 15:54:59 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	return (NULL);
}

/*
#include <stddef.h>
#include <stdio.h>
#include <string.h>
   
int     main(int argc, char **argv)
{
        if (argc == 2)
        {
                printf("Resultat de strrchr : %s\n", strrchr(argv[1], '\0'));
                printf("Resultat ft_strrchr : %s\n", ft_strrchr(argv[1], '\0'));
        }
        printf("\n");
        return (0);
}
*/
