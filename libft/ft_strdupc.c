/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:28:02 by cnorton-          #+#    #+#             */
/*   Updated: 2023/10/25 14:28:05 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdupc(const char *s1, int c)
{
	char	*ptr;
	size_t	len;

	len = 0;
	while (s1[len] && s1[len] != c)
		len++;
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len * sizeof(char) + 1);
	return (ptr);
}
