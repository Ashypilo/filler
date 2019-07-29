/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:14:05 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 16:47:34 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_memory(t_int *poin)
{
	uintmax_t	i;

	i = 1;
	if (poin->f < 0 || poin->zero_minus == 1)
	{
		i++;
		poin->f = poin->f * (-1);
	}
	while (poin->f >= 10)
	{
		poin->f = poin->f / 10;
		i++;
	}
	i++;
	if (poin->accuracy > 0)
		i = i + poin->accuracy;
	else
		i = i + 7;
	return (i);
}

static void		ft_basic_float(t_char *link, t_int *poin)
{
	poin->f = poin->type_float;
	poin->i = ft_memory(poin);
	link->type_string = (char*)malloc(sizeof(char) * (poin->i + 1));
	link->type_string[poin->i--] = '\0';
	if (poin->type_float < 0 || poin->zero_minus == 1)
		link->type_string[0] = '-';
	poin->f = poin->type_float;
	if (poin->type_float < 0 || poin->zero_minus == 1)
		poin->type_float = poin->type_float * (-1);
	poin->ac = 6;
	poin->f_f = poin->type_float;
	ft_string_float(link, poin);
}

void			ft_float_conversion(t_char *link, t_int *poin)
{
	if (1 / poin->type_float < 0)
		poin->zero_minus = 1;
	if (poin->type_float != poin->type_float)
	{
		link->type_string = ft_strdup("nan");
		link->f_plus = 0;
	}
	else if (poin->type_float * 2 == poin->type_float &&
			poin->type_float != 0 && poin->type_float < 0)
		link->type_string = ft_strdup("-inf");
	else if (poin->type_float * 2 == poin->type_float &&
			poin->type_float != 0 && poin->type_float > 0)
		link->type_string = ft_strdup("inf");
	else
		ft_basic_float(link, poin);
}
