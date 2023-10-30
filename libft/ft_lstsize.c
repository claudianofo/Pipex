/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:10:17 by cnorton-          #+#    #+#             */
/*   Updated: 2023/04/19 15:15:38 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*head;

	lst = ft_lstnew((void *)3);
	ft_lstadd_front(&lst, ft_lstnew((void *)2));
	ft_lstadd_front(&lst, ft_lstnew((void *)1));
	head = lst;
	while (lst) 
	{
		printf("lst: %d\n", (int)lst->content);
		lst = lst->next;
	}
	printf("size: %d\n", ft_lstsize(head));
	return (0);
}*/
