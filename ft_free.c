/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:35:04 by ashypilo          #+#    #+#             */
/*   Updated: 2019/04/21 13:44:15 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void	delete_insert(t_pointer *p)
{
	int			x;

	x = 0;
	while (p->insert[x] != NULL)
	{
		free(p->insert[x]);
		x++;
	}
	free(p->insert);
	p->insert = NULL;
}

void	delete_map(t_pointer *p)
{
	int			x;

	x = 0;
	while (p->map[x] != NULL)
	{
		free(p->map[x]);
		x++;
	}
	free(p->map);
	p->map = NULL;
}

void	delete_int_map(t_pointer *p)
{
	int			x;

	x = 0;
	while (x != p->x_map)
	{
		free(p->int_map[x]);
		x++;
	}
	free(p->int_map);
	p->int_map = 0;
}
