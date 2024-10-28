/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:57:35 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/27 11:38:22 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

int     main(void)
{
        int     content;
	int	content2;
	int	content3;
        t_list  *node;
	t_list	*node_ptr1;
	t_list	*node_ptr2;
	t_list	*node2;
	t_list	*node3;
        int     *node_value;

        content = 3;
        node = ft_lstnew((void *)&content);
        if (node)
        {
                node_value = (int *)node -> content;
                printf("Node value = %d\n", *node_value);
        }
	content2 = 2;
        node2 = ft_lstnew((void *)&content2);
        if (node2)
        {
                node_value = (int *)node->content;
                printf("Node value = %d\n", *node_value);
        }
	ft_lstadd_front(&node, node2);
	node_ptr1 = node;
	while (node_ptr1)
	{
		node_value = (int *)node_ptr1->content;
		printf("Node value after addition : %d\n", *node_value);
		node_ptr1 = node_ptr1->next;
	}
	content3 = 42;
        node3 = ft_lstnew((void *)&content3);
        if (node3)
        {
                node_value = (int *)node->content;
                printf("Node value = %d\n", *node_value);
        }
	ft_lstadd_front(&node, node3);
	node_ptr2 = node;
	while (node_ptr2)
	{
		node_value = (int *)node_ptr2->content;
		printf("Node value after addition : %d\n", *node_value);
		node_ptr2 = node_ptr2->next;
	}
	return (0);
}
*/
