/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:07:48 by cnorton-          #+#    #+#             */
/*   Updated: 2023/10/24 15:07:56 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

static char	**make_array(char const *s)
{
	int		i;
	int		count_str;
	char	**array;
	char	quote;

	i = 0;
	count_str = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
		{
			count_str++;
			if (s[i] == '\'' || s[i] == '\"')
			{
				quote = s[i++];
				while (s[i] && s[i] != quote)
					i++;
			}
			while (s[i] != ' ' && s[i])
				i++;
		}
		else
			i++;
	}
	return (array = (char **)malloc(sizeof(char *) * (count_str + 1)));
}

static char	**free_stuff(char **array, unsigned int i)
{
	while (i--)
		free(array[i]);
	free(array);
	return (NULL);
}
// if (s[j] == '\'' || s[j] == '\"')
		// {
		// 	array[i] = ft_strdupc(&s[j + 1], s[j]);
		// 	if (!array[i])
		// 		return (free_stuff(array, i));
		// 	j += ft_strlen(array[i++]) + 2;
		// }
		// else
		// {
		// 	array[i] = ft_strdupc(&s[j], ' ');
		// 	if (!array[i])
		// 		return (free_stuff(array, i));
		// 	j += ft_strlen(array[i++]) + 1;
		// }

static char	*get_string(char *s, unsigned int *offset)
{
	char	*str;

	if (*s == '\'' || *s == '\"')
	{
		str = ft_strdupc(s + 1, s[0]);
		if (!str)
			return (NULL);
		*offset += 2;
	}
	else
	{
		str = ft_strdupc(s, ' ');
		if (!str)
			return (NULL);
		*offset += 1;
	}
	return (str);
}

static char	**fill_array(char **array, char const *s)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s[j] && j < ft_strlen(s))
	{
		while (s[j] == ' ')
			j++;
		array[i] = get_string((char *)&s[j], &j);
		if (!array[i])
			return (free_stuff(array, i));
		j += ft_strlen(array[i++]);
	}
	array[i] = NULL;
	return (array);
}

char	**split_pipex(char const *s)
{
	char	**array;

	if (!s)
		return (0);
	array = make_array(s);
	if (!array)
		return (NULL);
	return (fill_array(array, s));
}
