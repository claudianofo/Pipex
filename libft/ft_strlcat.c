/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:19:31 by cnorton-          #+#    #+#             */
/*   Updated: 2023/05/07 16:52:24 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	j = len_dst;
	if (dstsize > 0 && j < dstsize)
	{
		while (src[i] != '\0' && i < (dstsize - j - 1))
		{
			dst[j + i] = src[i];
			i++;
		}
		dst[j + i] = '\0';
	}
	if (dstsize > len_dst)
		return (len_dst + ft_strlen(src));
	else
		return (ft_strlen(src) + dstsize);
}
