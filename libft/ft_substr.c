/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:45:34 by cnorton-          #+#    #+#             */
/*   Updated: 2023/04/25 21:54:59 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*sub;

	l = ft_strlen(s);
	if (l < start)
		return (ft_strdup(""));
	l -= start;
	if (len < l)
		l = len;
	sub = (char *)malloc(l + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	printf("%s", ft_substr("lorem ipsum dolor sit amet", 7, 10));
	return (0);
}*/
