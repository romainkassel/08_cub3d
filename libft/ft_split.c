/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:14:51 by Avandeve          #+#    #+#             */
/*   Updated: 2024/06/21 15:15:01 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	word_flag;
	int	word_count;

	i = 0;
	word_flag = 0;
	word_count = 0;
	while (str[i])
	{
		if (str[i] != sep && word_flag == 0)
		{
			word_flag = 1;
			word_count++;
		}
		else if (str[i] == sep)
			word_flag = 0;
		i++;
	}
	return (word_count);
}

char	*ft_strcpy(char *dest, const char *src, char sep)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != sep)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free(char **words_array, int count)
{
	int	i;

	i = 0;
	if (words_array)
	{
		while (i < count - 1)
		{
			if (words_array[i])
				free(words_array[i]);
			i++;
		}
		free(words_array);
	}
	return ;
}

char	**ft_split_words(char **array, const char *str, char sep, size_t w)
{
	size_t	i;
	size_t	j;
	size_t	word_pos;

	i = 0;
	word_pos = 0;
	while (word_pos < w)
	{
		if (str[i] == sep)
			i++;
		else
		{
			j = 0;
			while (str[i + j] && str[i + j] != sep)
				j++;
			array[word_pos] = ft_calloc((j + 1), sizeof(char));
			if (!array[word_pos])
				return (ft_free(array, word_pos), NULL);
			ft_strcpy(array[word_pos], str + i, sep);
			i = i + j;
			word_pos++;
		}
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**words_array;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	words_array = ft_calloc((words + 1), sizeof(char *));
	if (!words_array)
		return (NULL);
	if (!ft_split_words(words_array, s, c, words))
		return (NULL);
	return (words_array);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{	
	i = 0;
	if (argc != 3)
		printf("Arguments missing");
	else
	{
		str = argv[1];
		sep = argv[2][0];
		words_array = ft_split(str, sep);
		printf("Initial string : %s, the separator was : %c\n", str, sep);
		printf("The split strings are :");
		while (words_array[i])
		{
			j = 0;
			while (words_array[i][j] != '\0')
			{
				write(1, &words_array[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
		write(1, "\n", 1);
		ft_free(words_array, i);
	}
	return (0);
}
*/
