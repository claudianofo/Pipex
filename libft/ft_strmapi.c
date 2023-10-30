/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 20:01:33 by cnorton-          #+#    #+#             */
/*   Updated: 2023/04/25 21:57:32 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	len;
	unsigned int	i;

	len = ft_strlen(s);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (0);
	dst[len] = '\0';
	i = 0;
	while (i < len)
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	return (dst);
}
