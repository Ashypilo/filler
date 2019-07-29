/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:27:19 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 17:23:30 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_memory_allocation(t_char *link, t_int *poin)
{
	intmax_t i;

	i = 0;
	if (poin->width > poin->accuracy)
		i = poin->width + 3;
	else if (poin->width < poin->accuracy)
		i = poin->accuracy + 3;
	else if (poin->width == poin->accuracy &&
			poin->string_value < poin->accuracy)
		i = poin->accuracy + 3;
	else
		i = poin->string_value + 3;
	link->output = (char *)malloc(sizeof(char) * (i));
	link->output[i] = '\0';
}

static int		ft_definition_long_flaggs(t_char *link, intmax_t i)
{
	if (link->f_hash == '#')
	{
		if (link->type == 'x' || link->type == 'X' || link->type == 'p')
			i = 2;
		else if (link->type == 'o' && link->type_string[0] != '0')
			i = 1;
	}
	if (link->f_plus == '+' && link->type_string[0] != '-' && link->type != 0)
		i++;
	else if (link->f_space == ' ' && link->type_string[0] != '-' &&
			link->type != 0)
		i++;
	return (i);
}

static void		ft_def_string_value(t_int *poin, t_char *link)
{
	if (link->type == '%')
		poin->string_value = 1;
	if (link->type == 's')
		poin->accuracy = 0;
	else if (link->type == 'o' && link->f_zero == '0' && poin->accuracy > 0)
		poin->accuracy = poin->accuracy - poin->string_value - 1;
	else if (poin->accuracy > poin->string_value &&
			*link->type_string != '\0' && link->type_string[0] != '-')
		poin->accuracy = poin->accuracy - poin->string_value;
	else if (poin->accuracy > poin->string_value &&
			*link->type_string != '\0' && link->type_string[0] == '-')
		poin->accuracy = poin->accuracy - poin->string_value + 1;
	else if (poin->accuracy == 0)
	{
		if (poin->accuracy == poin->string_value &&
			poin->string_value > 0 && link->type != 's')
			poin->accuracy = 1;
	}
	else
		poin->accuracy = 0;
}

static void		ft_definition_width_acc(t_char *link, t_int *poin, intmax_t i)
{
	i = ft_definition_long_flaggs(link, i);
	if (link->type == 's')
	{
		if (poin->not_acc == 1 && poin->accuracy == 0)
			poin->string_value = 0;
		else if (poin->accuracy < poin->string_value && poin->not_acc == 1)
			poin->string_value = poin->accuracy;
	}
	if (link->type == 'c')
		poin->accuracy = 0;
	ft_def_string_value(poin, link);
	if (poin->argument == -1 && poin->not_acc == 1)
		poin->accuracy = 1;
	i = poin->accuracy + poin->string_value + i;
	if (poin->width > i)
		poin->width = poin->width - i;
	else
		poin->width = 0;
}

int				ft_type(t_char *link, t_int *poin)
{
	intmax_t i;

	i = 0;
	poin->string_value = 0;
	if (*link->type_string != '0' && link->type != 'c')
		poin->string_value = ft_strlen(link->type_string);
	else if ((link->type != 'f' && *link->type_string == '0' &&
			poin->not_acc != 1) || link->type == 'c')
		poin->string_value = 1;
	else if (*link->type_string == '0' && link->type == 'o' &&
			poin->not_acc == 1 && link->f_hash == '#')
		poin->string_value = 1;
	else if (*link->type_string == '0' && link->type == 'f')
		poin->string_value = ft_strlen(link->type_string);
	if (poin->string_value == 0 && link->type == 0 && poin->width != 0)
		poin->string_value = 1;
	ft_memory_allocation(link, poin);
	link->output_head = link->output;
	ft_definition_width_acc(link, poin, i);
	poin->characters = ft_output(link, poin, i);
	return (poin->characters);
}
