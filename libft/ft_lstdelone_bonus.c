/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:52:08 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/28 19:14:02 by Avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
static void	del_content(void *content)
{
	free(content);
}
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h> 

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*current;

	node1 = ft_lstnew("Hello");
	node2 = ft_lstnew(" ");
	node3 = ft_lstnew("World!");

	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	ft_lstdelone(node3, node3->content);
	current = node1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstdelone(node3, node3->content);
	current = node1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}
*/
