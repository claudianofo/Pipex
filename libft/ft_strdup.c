/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:43:09 by cnorton-          #+#    #+#             */
/*   Updated: 2023/05/02 16:42:24 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(s1);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, len * sizeof(char) + 1);
	return (ptr);
}
/*
The strdup() function allocates suffi-
     cient memory for a copy of the string
     s1, does the copy, and returns a
     pointer to it.  The pointer may subse-
     quently be used as an argument to the
     function free(3).

     If insufficient memory is available,
     NULL is returned
}*/
