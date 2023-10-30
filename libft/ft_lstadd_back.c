/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:28:09 by cnorton-          #+#    #+#             */
/*   Updated: 2023/04/25 14:46:50 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!*lst)
		*lst = new;
	else
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
/*
int	main(void)
{
	t_list	*lst;
	t_list  *head;

	lst = ft_lstnew((void *)1);
	ft_lstadd_back(&lst, ft_lstnew((void *)2));
	head = lst;
	while (lst) 
	{
		printf("lst: %d\n", (int)lst->content);
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
