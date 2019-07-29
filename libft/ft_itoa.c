/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:57:44 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/18 16:52:04 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_memory(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char		*ft_outp(char *fresh, int n, int i)
{
	while (n > 9)
	{
		fresh[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	fresh[i] = n + 48;
	return (fresh);
}

char			*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*fresh;

	j = n;
	if (n < 0)
		n = n * (-1);
	i = ft_memory(j);
	if (n - 1 == 2147483647)
	{
		fresh = ft_strdup("-2147483648");
		return (fresh);
	}
	fresh = (char*)malloc(i + 1);
	if (fresh != NULL)
	{
		if (j < 0)
			fresh[0] = '-';
		fresh[i--] = '\0';
		fresh = ft_outp(fresh, n, i);
		return (fresh);
	}
	return (NULL);
}
