/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:16:11 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/29 11:32:19 by amelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!(*lst) || !del || !lst)
		return ;
	while (*lst)
	{
		ft_lstclear(&(*lst)->next, del);
		(del)((*lst)->content);
		free(*lst);
		*lst = NULL;
	}
}
