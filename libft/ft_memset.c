/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:45 by cnorton-          #+#    #+#             */
/*   Updated: 2023/03/21 16:22:33 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char			*b1;
	unsigned char	c1;

	b1 = (char *)b;
	c1 = (unsigned char)c;
	while (len > 0)
	{
		b1[len - 1] = c1;
		len--;
	}
	return (b);
}
