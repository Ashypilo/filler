/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:29:53 by ashypilo          #+#    #+#             */
/*   Updated: 2019/04/20 15:04:01 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void	put_numbers_next(t_pointer *p, int i, int j)
{
	if (i - 1 >= 0 && j - 1 >= 0 && p->int_map[i - 1][j - 1] != 0 &&
		p->int_map[i - 1][j - 1] != p->num_fill - 1 && p->int_map[i - 1][j - 1]
		!= p->num_fill && p->int_map[i - 1][j - 1] != p->y_map + 1)
		p->int_map[i - 1][j - 1] = p->num_fill + 1;
	if (i - 1 >= 0 && j + 1 != p->y_map && p->int_map[i - 1][j + 1] != 0 &&
		p->int_map[i - 1][j + 1] != p->num_fill - 1 && p->int_map[i - 1][j + 1]
		!= p->num_fill && p->int_map[i - 1][j + 1] != p->y_map + 1)
		p->int_map[i - 1][j + 1] = p->num_fill + 1;
	if (i + 1 != p->x_map && j + 1 != p->y_map && p->int_map[i + 1][j + 1]
		!= 0 && p->int_map[i + 1][j + 1] != p->num_fill - 1 &&
		p->int_map[i + 1][j + 1] != p->num_fill && p->int_map[i + 1][j + 1]
		!= p->y_map + 1)
		p->int_map[i + 1][j + 1] = p->num_fill + 1;
	if (i + 1 != p->x_map && j - 1 >= 0 && p->int_map[i + 1][j - 1] != 0 &&
		p->int_map[i + 1][j - 1] != p->num_fill - 1 && p->int_map[i + 1][j - 1]
		!= p->num_fill && p->int_map[i + 1][j - 1] != p->y_map + 1)
		p->int_map[i + 1][j - 1] = p->num_fill + 1;
}

static	void	put_numbers(t_pointer *p, int i, int j)
{
	if (i - 1 >= 0 && p->int_map[i - 1][j] != 0 && p->int_map[i - 1][j] !=
		p->num_fill - 1 && p->int_map[i - 1][j] != p->num_fill &&
		p->int_map[i - 1][j] != p->y_map + 1)
		p->int_map[i - 1][j] = p->num_fill + 1;
	if (i + 1 != p->x_map && p->int_map[i + 1][j] != 0 && p->int_map[i + 1][j]
		!= p->num_fill - 1 && p->int_map[i + 1][j] != p->num_fill &&
		p->int_map[i + 1][j] != p->y_map + 1)
		p->int_map[i + 1][j] = p->num_fill + 1;
	if (j - 1 >= 0 && p->int_map[i][j - 1] != 0 && p->int_map[i][j - 1] !=
		p->num_fill - 1 && p->int_map[i][j - 1] != p->num_fill &&
		p->int_map[i][j - 1] != p->y_map + 1)
		p->int_map[i][j - 1] = p->num_fill + 1;
	if (j + 1 != p->y_map && p->int_map[i][j + 1] != 0 && p->int_map[i][j + 1]
		!= p->num_fill - 1 && p->int_map[i][j + 1] != p->num_fill &&
		p->int_map[i][j + 1] != p->y_map + 1)
		p->int_map[i][j + 1] = p->num_fill + 1;
	put_numbers_next(p, i, j);
}

static	void	ft_fill_number_int_map(t_pointer *p)
{
	int			i;
	int			j;

	i = 0;
	while (i < p->x_map)
	{
		j = 0;
		while (j < p->y_map)
		{
			if (p->int_map[i][j] == p->num_fill)
				put_numbers(p, i, j);
			j++;
		}
		i++;
	}
}

static	void	filling_int_map_players(t_pointer *p, int i, int j)
{
	while (p->map[p->x_map_dub])
	{
		p->y_map_dub = 0;
		j = 0;
		while (p->map[p->x_map_dub][p->y_map_dub] != '\0')
		{
			if (p->map[p->x_map_dub][p->y_map_dub] == p->player_second)
				p->int_map[i][j++] = p->num_fill;
			else if (p->map[p->x_map_dub][p->y_map_dub] == p->player)
				p->int_map[i][j++] = p->y_map + 1;
			else if (p->map[p->x_map_dub][p->y_map_dub] != '\0')
				p->int_map[i][j++] = p->y_map;
			p->y_map_dub++;
		}
		p->x_map_dub++;
		i++;
	}
}

void			calculation(t_pointer *p)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	p->add = 0;
	p->add_out = 0;
	p->x_map_dub = 0;
	p->x_out = 0;
	p->y_out = 0;
	p->num_fill = 0;
	filling_int_map_players(p, i, j);
	while (p->num_fill < p->y_map)
	{
		ft_fill_number_int_map(p);
		p->num_fill++;
	}
	p->x_map_dub = 0;
	p->in_x_dub = 0;
	p->stop = 0;
	search_coordinate(p);
}
