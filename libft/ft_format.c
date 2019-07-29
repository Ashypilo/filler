/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:49:43 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 17:22:08 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*unsig(t_char *link, t_int *poin, char *s, uintmax_t t_sys)
{
	uintmax_t	arg_unsig;
	int			i;

	i = 0;
	arg_unsig = poin->argument;
	while (arg_unsig >= t_sys)
	{
		arg_unsig = arg_unsig / t_sys;
		i++;
	}
	link->type_string = ft_strnew(i + 1);
	arg_unsig = poin->argument;
	i++;
	link->type_string[i--] = '\0';
	while (arg_unsig >= t_sys)
	{
		link->type_string[i] = s[arg_unsig % t_sys];
		arg_unsig = arg_unsig / t_sys;
		i--;
	}
	link->type_string[i] = s[arg_unsig % t_sys];
	poin->type_system = t_sys;
	return (link->type_string);
}

static void		ft_get_o_u_x(va_list ap, t_char *link, t_int *poin)
{
	if (link->size[0] == 'l' && link->size[1] == 'l')
		poin->argument = va_arg(ap, unsigned long long int);
	else if (link->size[0] == 'l')
		poin->argument = va_arg(ap, unsigned long int);
	else if (link->size[0] == 'h' && link->size[1] == 'h')
		poin->argument = (unsigned char)va_arg(ap, unsigned int);
	else if (link->size[0] == 'h')
		poin->argument = (unsigned short int)va_arg(ap, unsigned int);
	else if (link->size[0] == 'j')
		poin->argument = va_arg(ap, intmax_t);
	else if (link->size[0] == 'z')
		poin->argument = va_arg(ap, size_t);
	else
		poin->argument = va_arg(ap, unsigned int);
}

static void		ft_o_u_x_p(t_char *link, t_int *poin, va_list ap)
{
	if (link->type == 'o' || link->type == 'u')
	{
		ft_get_o_u_x(ap, link, poin);
		if (link->type == 'o')
			link->type_string = unsig(link, poin, "01234567", 8);
		else if (link->type == 'u')
			link->type_string = unsig(link, poin, "0123456789", 10);
	}
	else if (link->type == 'x' || link->type == 'X' || link->type == 'p')
	{
		if (link->type == 'p')
			poin->argument = va_arg(ap, long long int);
		else
			ft_get_o_u_x(ap, link, poin);
		if (link->type == 'x' || link->type == 'p')
			link->type_string = unsig(link, poin, "0123456789abcdef", 16);
		else
			link->type_string = unsig(link, poin, "0123456789ABCDEF", 16);
	}
}

int				ft_format(t_char *link, t_int *poin, va_list ap)
{
	if (link->f_hash == '#' && link->type == 'c')
		link->f_hash = '1';
	if (link->f_plus == '+' && (link->type == 'o' || link->type == 'u' ||
		link->type == 'x' || link->type == 'p' || link->type == 'c' ||
			link->type == 's'))
		link->f_plus = '1';
	if (link->f_space == ' ' && (link->type == 'o' || link->type == 'u' ||
		link->type == 'x' || link->type == 'p' || link->type == 'c' ||
			link->type == 's'))
		link->f_space = '1';
	if (link->type == 'o' || link->type == 'u' || link->type == 'x' ||
		link->type == 'X' || link->type == 'p')
		ft_o_u_x_p(link, poin, ap);
	else if (link->type == 'd' || link->type == 'i' || link->type == 'c' ||
		link->type == 's' || link->type == 'f')
		ft_dicsf(link, poin, ap);
	else
		link->type_string = ft_strnew(1);
	poin->characters = ft_type(link, poin);
	return (poin->characters);
}
