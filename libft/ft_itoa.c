/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnorton- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:34:45 by cnorton-          #+#    #+#             */
/*   Updated: 2023/04/25 21:57:19 by cnorton-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long nb)
{
	int	len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 9)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static void	convert(char *str, long nb, int i)
{
	while (nb > 0)
	{
		str[i] = 48 + (nb % 10);
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nb;

	nb = n;
	i = int_len(nb);
	str = (char *)malloc(i + 1);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	convert(str, nb, i);
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-2147483647));
	return (0);
}*/
