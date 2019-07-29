/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d_i_c_s_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 13:10:59 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 17:23:59 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_malloc_string(t_int *poin, t_char *link, int t_syst)
{
	if (poin->argument < 0)
	{
		poin->argument = poin->argument * (-1);
		poin->i_arg++;
		poin->k_min++;
	}
	poin->rev_o = poin->argument;
	while (poin->rev_o >= t_syst)
	{
		poin->rev_o = poin->rev_o / t_syst;
		poin->i_arg++;
	}
	link->type_string = ft_strnew(poin->i_arg);
	link->type_string[poin->i_arg] = '\0';
}

static void	ft_arg_minus(t_int *poin, t_char *link, char *string)
{
	poin->i_arg = 0;
	poin->rev_o = poin->argument;
	while (poin->rev_o < 0)
	{
		poin->rev_o = poin->rev_o / 10;
		poin->i_arg++;
	}
	link->type_string = ft_strnew(poin->i_arg);
	link->type_string[0] = '-';
	while (poin->argument < 0)
	{
		link->type_string[poin->i_arg] = string[(poin->argument % -10) * -1];
		poin->argument = poin->argument / 10;
		poin->i_arg--;
	}
}

static char	*ft_trfer(t_char *link, t_int *poin, char *string, int t_syst)
{
	poin->i_arg = 0;
	poin->k_min = 0;
	ft_malloc_string(poin, link, t_syst);
	poin->rev_o = poin->argument;
	link->type_string[poin->i_arg + 1] = '\0';
	if (poin->k_min == 1)
	{
		link->type_string[0] = '-';
		poin->argument = poin->argument * (-1);
	}
	if (poin->rev_o >= 0)
	{
		while (poin->rev_o >= t_syst)
		{
			link->type_string[poin->i_arg] = string[poin->rev_o % t_syst];
			poin->rev_o = poin->rev_o / t_syst;
			poin->i_arg--;
		}
		link->type_string[poin->i_arg] = string[poin->rev_o % t_syst];
	}
	else if (poin->argument < 0)
		ft_arg_minus(poin, link, string);
	poin->type_system = t_syst;
	return (link->type_string);
}

static void	ft_getting_d_i_f(va_list ap, t_char *link, t_int *poin)
{
	if (link->type == 'f')
	{
		if (link->size[0] == 'L')
			poin->type_float = va_arg(ap, long double);
		else
			poin->type_float = va_arg(ap, double);
	}
	else
	{
		if (link->size[0] == 'l' && link->size[1] == 'l')
			poin->argument = va_arg(ap, long long int);
		else if (link->size[0] == 'l')
			poin->argument = va_arg(ap, long int);
		else if (link->size[0] == 'h' && link->size[1] == 'h')
			poin->argument = (signed char)va_arg(ap, int);
		else if (link->size[0] == 'h')
			poin->argument = (short int)va_arg(ap, int);
		else if (link->size[0] == 'j')
			poin->argument = va_arg(ap, intmax_t);
		else if (link->size[0] == 'z')
			poin->argument = va_arg(ap, size_t);
		else
			poin->argument = va_arg(ap, int);
		link->type_string = ft_trfer(link, poin, "0123456789", 10);
	}
}

void		ft_dicsf(t_char *link, t_int *poin, va_list ap)
{
	if (link->type == 'd' || link->type == 'i')
		ft_getting_d_i_f(ap, link, poin);
	else if (link->type == 'c')
	{
		link->type_string = (char*)ft_strnew(0);
		if (link->size[0] == 'l')
			link->type_c = (wchar_t)va_arg(ap, int);
		else
			link->type_c = (unsigned char)va_arg(ap, int);
		link->type_string[0] = link->type_c;
	}
	else if (link->type == 's')
	{
		link->type_string = ft_strdup(va_arg(ap, char*));
		if (link->type_string == NULL)
			link->type_string = ft_strdup("(null)");
	}
	else if (link->type == 'f')
	{
		ft_getting_d_i_f(ap, link, poin);
		poin->zero_minus = 0;
		ft_float_conversion(link, poin);
	}
}
