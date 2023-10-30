/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 22:20:06 by cnorton-          #+#    #+#             */
/*   Updated: 2023/05/02 16:10:29 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**make_array(char const *s, char c)
{
	int		i;
	int		count_str;
	char	**array;

	i = 0;
	count_str = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count_str++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	array = (char **)malloc(sizeof(char *) * (count_str + 1));
	return (array);
}

static char	**free_things(char **array, unsigned int i)
{
	while (i--)
		free(array[i]);
	free(array);
	return (NULL);
}

static char	**fill_array(char **array, char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (s[j] && j < ft_strlen(s))
	{
		while (s[j] == c)
			j++;
		k = j;
		while (s[j] && s[j] != c)
			j++;
		if (j > k)
		{
			array[i] = ft_substr(&s[k], 0, j - k);
			if (!array[i])
				return (free_things(array, i));
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	array = make_array(s, c);
	if (!array)
		return (NULL);
	if (!s)
		return (0);
	return (fill_array(array, s, c));
}
/*
int	main(void)
{
	char	**array;
	int		i;

	array = ft_split("hello!", ' ');
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	return (0);
}*/
