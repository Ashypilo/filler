/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:06:29 by ashypilo          #+#    #+#             */
/*   Updated: 2019/02/01 17:06:30 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_memory(intmax_t n)
{
	intmax_t		i;

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

static char			*ft_outp(char *fresh, intmax_t n, intmax_t i)
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

char				*ft_itoa_base(intmax_t n)
{
	intmax_t		i;
	intmax_t		j;
	char			*fresh;

	j = n;
	if (n < 0)
		n = n * (-1);
	i = ft_memory(j);
	fresh = (char*)malloc(sizeof((char*)i + 1));
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
