/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:22:43 by cnorton-          #+#    #+#             */
/*   Updated: 2023/03/22 18:34:39 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;
	size_t	i;

	if (!src && !dst)
		return (0);
	dst1 = (char *)dst;
	src1 = (char *)src;
	i = 0;
	while (len > 0 && i < len)
	{
		if (src1 < dst1)
		{
			dst1[len - 1] = src1[len - 1];
			len--;
		}
		else
		{
			dst1[i] = src1[i];
			i++;
		}
	}
	return (dst);
}
