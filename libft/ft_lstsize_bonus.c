/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Avandeve <Avandeve@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:44:31 by Avandeve          #+#    #+#             */
/*   Updated: 2024/04/27 11:52:25 by Avandeve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		count;

	count = 0;
	ptr = NULL;
	if (!lst)
		return (0);
	ptr = lst;
	while (ptr->next != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	if (ptr->next == NULL)
		count++;
	return (count);
}
