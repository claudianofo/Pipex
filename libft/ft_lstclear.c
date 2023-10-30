/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:52:30 by cnorton-          #+#    #+#             */
/*   Updated: 2023/04/25 15:28:38 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		head = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(head);
	}
}
