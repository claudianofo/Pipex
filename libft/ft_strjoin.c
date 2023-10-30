/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:45:56 by cnorton-          #+#    #+#             */
/*   Updated: 2023/05/02 16:30:57 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*new;

	l = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(l + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, l + 1);
	ft_strlcat(new, s2, l + 1);
	return (new);
}
/*
int	main(void)
{
	printf("%s", ft_strjoin("hello ", "goodbye"));
	return (0);
}*/
