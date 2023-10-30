/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:09:19 by cnorton-          #+#    #+#             */
/*   Updated: 2023/04/19 15:24:31 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*lst;
	t_list  *head;

	lst = ft_lstnew((void *)121);
	ft_lstadd_front(&lst, ft_lstnew((void *)122));
	head = lst;
	while (lst) 
	{
		printf("lst: %c\n", (char)lst->content);
		lst = lst->next;
	}
	lst = head;
	while (lst)
	{
		lst = lst->next;
		free(head);
		head = lst;
	}
}*/
