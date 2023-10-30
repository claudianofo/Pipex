/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:17:53 by cnorton-          #+#    #+#             */
/*   Updated: 2023/10/17 16:17:58 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_things(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_rm_quotes(char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '\'')
			cmd[i] = ft_strtrim(cmd[i], "\'");
		if (cmd[i][0] == '\"')
			cmd[i] = ft_strtrim(cmd[i], "\"");
		i++;
	}
	return (cmd);
}
