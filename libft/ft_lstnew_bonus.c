/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:40:17 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/26 17:56:58 by Avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *) malloc (sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int	main(void)
{
	int	content;
	t_list	*node;
	int	*node_value;

	content = 3;
	node = ft_lstnew((void *)&content);
	if (node)
	{
		node_value = (int *)node -> content;
		printf("Node value = %d\n", *node_value);
	}
	return (0);
}
*/
