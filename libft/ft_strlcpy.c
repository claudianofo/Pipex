/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:57:52 by cnorton-          #+#    #+#             */
/*   Updated: 2023/05/02 17:03:57 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*strlcpy() and strlcat() take
     the full size of the destina-
     tion buffer and guarantee NUL-
     termination if there is room.
     Note that room for the NUL
     should be included in dstsize.

     strlcpy() copies up to dstsize
     - 1 characters from the string
     src to dst, NUL-terminating
     the result if dstsize is not
     0. It returns the length of the src */
