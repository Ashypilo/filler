/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:19:05 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 17:22:49 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_f_oktotop(t_char *link, t_int *poin, intmax_t i)
{
	if (poin->type_system == 16)
		link->output[i++] = '0';
	else if (poin->type_system == 8)
		link->output[i++] = '0';
	if (link->type == 'x' || link->type == 'p')
		link->output[i++] = 'x';
	else if (link->type == 'X')
		link->output[i++] = 'X';
	return (i);
}

static int		ft_flaggs_not_minus(t_char *link, t_int *poin, intmax_t i)
{
	while (poin->width-- > 0)
		link->output[i++] = ' ';
	if (link->f_space == ' ' && link->type_string[0] != '-' &&
		link->f_plus != '+' && link->type != '%' && link->type != 0)
		link->output[i++] = ' ';
	if (link->f_plus == '+' && link->type_string[0] != '-' && link->type != 0)
		link->output[i++] = '+';
	if (link->f_hash == '#' && *link->type_string != '0')
		i = ft_f_oktotop(link, poin, i);
	else if (link->type == 'p')
		i = ft_f_oktotop(link, poin, i);
	if (link->type_string[0] == '-')
	{
		link->output[i++] = *link->type_string++;
		poin->string_value--;
	}
	while (poin->accuracy-- > 0)
		link->output[i++] = '0';
	if (link->type != '%')
		while (poin->string_value-- > 0)
			link->output[i++] = *link->type_string++;
	else
		link->output[i++] = link->type;
	return (i);
}

static int		ft_flagg_minus(t_char *link, t_int *poin, intmax_t i)
{
	if (link->f_space == ' ' && link->type_string[0] != '-' &&
		link->f_plus != '+' && link->type != '%')
		link->output[i++] = ' ';
	if (link->f_plus == '+' && link->type_string[0] != '-')
		link->output[i++] = '+';
	if (link->f_hash == '#' && *link->type_string != '0')
		i = ft_f_oktotop(link, poin, i);
	if (link->type_string[0] == '-')
	{
		link->output[i++] = *link->type_string++;
		poin->string_value--;
	}
	while (poin->accuracy-- > 0)
		link->output[i++] = '0';
	if (link->type != '%')
		while (poin->string_value-- > 0)
			link->output[i++] = *link->type_string++;
	else
		link->output[i++] = link->type;
	while (poin->width-- > 0 && link->f_minus == '-')
		link->output[i++] = ' ';
	return (i);
}

int				ft_output(t_char *link, t_int *poin, intmax_t i)
{
	char *type;

	type = link->type_string;
	if (link->f_minus != '-')
	{
		if (link->f_zero == '0')
			i = ft_flagg_zero(link, poin, i);
		else
			i = ft_flaggs_not_minus(link, poin, i);
	}
	else
		i = ft_flagg_minus(link, poin, i);
	write(1, link->output_head, i);
	free(link->output);
	free(link->size);
	if (type)
		free(type);
	return (i);
}
