/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:30:24 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 16:51:55 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_outpu(t_int *poin, t_char *link, intmax_t ac)
{
	while (ac > 0)
	{
		poin->type_float = poin->type_float * 10;
		poin->k = poin->type_float;
		poin->type_float -= poin->k;
		link->type_string[poin->i++] = (poin->k % 10) + 48;
		ac--;
	}
	poin->type_float = poin->type_float * 10;
	poin->n_k = poin->type_float;
	if (poin->n_k != 0)
	{
		if (poin->n_k > 5)
			poin->k++;
		link->type_string[poin->i - 1] = (poin->k % 10) + 48;
	}
	link->type_string[poin->i] = '\0';
}

static void			ft_oprede(t_char *link, t_int *poin)
{
	poin->type_float = poin->type_float + poin->f_f;
	poin->k = poin->type_float;
	poin->type_float = poin->type_float - poin->k;
	if (poin->accuracy > 0)
		poin->j = poin->i - poin->accuracy;
	else
		poin->j = poin->i - 6;
	if (poin->f < 0 || poin->zero_minus == 1)
		poin->i = 1;
	else
		poin->i = 0;
	link->fresh_dub = ft_strnew(poin->j);
	poin->j = 0;
	if (poin->accuracy != 0)
		link->fresh_dub[poin->j++] = '.';
	else if (poin->accuracy == 0 && poin->not_acc == 0)
		link->fresh_dub[poin->j++] = '.';
	else if (link->f_hash == '#')
		link->fresh_dub[poin->j++] = '.';
}

static long double	ac_ze(t_int *poin, long double fract)
{
	if ((int)((poin->f_f)) % 2 != 0)
	{
		poin->k = poin->f_f;
		poin->f_f *= 10.0;
		poin->f_f -= poin->k * 10;
		if ((int)poin->f_f > 4)
			return (fract);
	}
	else if ((int)((poin->f_f)) % 2 == 0)
	{
		poin->k = poin->f_f;
		poin->f_f *= 10.0;
		poin->f_f -= poin->k * 10;
		if ((int)poin->f_f > 5)
			return (fract);
	}
	return (0);
}

static long double	round(int ac, t_int *poin)
{
	int				index;
	long double		fract;

	index = ac;
	fract = 1.0;
	if (ac == 0)
		return (ac_ze(poin, fract));
	while (index-- > 0 && ac > 0)
	{
		fract /= 10.0;
		poin->f_f *= 10.0;
		poin->k = poin->f_f;
		poin->f_f -= poin->k;
	}
	while ((int)poin->f_f > 9)
		poin->f_f /= 10.0;
	if ((int)((poin->f_f) * 10) > 4)
	{
		fract /= 10;
		return (fract);
	}
	return (0);
}

void				ft_string_float(t_char *link, t_int *poin)
{
	if (poin->accuracy > 0 || poin->not_acc == 1)
		poin->f_f = round(poin->accuracy, poin);
	else
		poin->f_f = round(poin->ac, poin);
	ft_oprede(link, poin);
	while (poin->k >= 10)
	{
		link->fresh_dub[poin->j++] = (poin->k % 10) + 48;
		poin->k = poin->k / 10;
	}
	link->fresh_dub[poin->j++] = (poin->k % 10) + 48;
	poin->j--;
	while (poin->j >= 0)
	{
		link->type_string[poin->i] = link->fresh_dub[poin->j];
		poin->j--;
		poin->i++;
	}
	if (poin->accuracy > 0)
		ft_outpu(poin, link, poin->accuracy);
	else if (poin->not_acc != 1)
		ft_outpu(poin, link, poin->ac);
	free(link->fresh_dub);
}
