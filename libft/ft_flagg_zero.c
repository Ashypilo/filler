/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagg_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:51:00 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 17:13:06 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_zero_hesh(t_char *link, t_int *poin, intmax_t i)
{
	if (poin->not_acc != 1)
	{
		if (link->f_hash == '#')
			i = ft_f_oktotop(link, poin, i);
		while (poin->width-- > 0)
			link->output[i++] = '0';
	}
	else if (link->type == 'f')
	{
		if (link->f_hash == '#')
			i = ft_f_oktotop(link, poin, i);
		while (poin->width-- > 0)
			link->output[i++] = '0';
	}
	else
	{
		while (poin->width-- > 0)
			link->output[i++] = ' ';
		if (link->f_hash == '#')
			i = ft_f_oktotop(link, poin, i);
	}
	return (i);
}

static int	ft_output_zero(t_char *link, t_int *poin, intmax_t i)
{
	if (link->type_string[0] == '-' && poin->not_acc == 1)
	{
		link->output[i++] = *link->type_string++;
		poin->string_value--;
	}
	else if (link->f_plus == '+' && link->type_string[0] != '-' &&
		link->type != 0 && poin->not_acc == 1 && link->type != 'f')
		link->output[i++] = '+';
	while (poin->accuracy-- > 0)
		link->output[i++] = '0';
	if (link->type != '%')
		while (poin->string_value-- > 0)
			link->output[i++] = *link->type_string++;
	else
		link->output[i++] = link->type;
	return (i);
}

int			ft_flagg_zero(t_char *link, t_int *poin, intmax_t i)
{
	if (link->f_space == ' ' && link->type_string[0] != '-' &&
		link->type != 0 && link->type != '%')
		link->output[i++] = ' ';
	if (link->f_plus == '+' && link->type_string[0] != '-' &&
		link->type != 0 && poin->not_acc == 0)
		link->output[i++] = '+';
	if (link->type_string[0] == '-' && poin->not_acc == 0)
	{
		link->output[i++] = *link->type_string++;
		poin->string_value--;
	}
	else if (link->type == 'f' && link->type_string[0] == '-')
	{
		link->output[i++] = *link->type_string++;
		poin->string_value--;
	}
	i = ft_zero_hesh(link, poin, i);
	i = ft_output_zero(link, poin, i);
	return (i);
}
