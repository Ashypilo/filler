/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_coordinate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:10:14 by ashypilo          #+#    #+#             */
/*   Updated: 2019/04/21 13:49:59 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void	finding_insert(t_pointer *p, t_link *link)
{
	if (p->insert[link->x][link->y] == '*' && p->int_map[link->i][link->j] != 0)
	{
		if (p->int_map[link->i][link->j] != p->y_map + 1)
		{
			link->out = link->out + p->int_map[link->i][link->j];
			link->insert++;
		}
		else if (p->int_map[link->i][link->j] == p->y_map + 1)
		{
			link->out = link->out + p->int_map[link->i][link->j];
			p->stop++;
			link->insert++;
		}
	}
	else if (p->insert[link->x][link->y] == '*' &&
			p->int_map[link->i][link->j] == 0)
	{
		link->out = 0;
		link->insert = 0;
		return ;
	}
}

static	void	search(t_pointer *p, t_link *link)
{
	if (p->stop != link->insert_player + 1 && link->insert < p->add)
	{
		finding_insert(p, link);
		if (link->insert == p->add && p->stop == link->insert_player)
		{
			if (p->add_out == 0)
			{
				p->add_out = link->out;
				p->x_out = link->x_out;
				p->y_out = link->y_out;
			}
			else if (p->add_out > link->out)
			{
				p->add_out = link->out;
				p->x_out = link->x_out;
				p->y_out = link->y_out;
			}
			link->insert = 0;
			link->out = 0;
			p->stop = 0;
		}
	}
	else
		return ;
}

static	void	insert_tetri(t_pointer *p, t_link *link)
{
	p->stop = 0;
	p->in_x_dub = 0;
	link->out = 0;
	link->insert = 0;
	link->x = 0;
	link->i = p->x_map_dub;
	link->j = p->y_map_dub;
	link->x_out = link->i;
	link->y_out = link->j;
	while (p->insert[link->x] && link->i < p->x_map)
	{
		link->y = 0;
		while (p->insert[link->x][link->y] && link->j < p->y_map)
		{
			search(p, link);
			link->y++;
			link->j++;
		}
		link->x++;
		link->i++;
		link->j -= link->y;
	}
}

static	void	start_search(t_pointer *p, t_link *link)
{
	p->x_map_dub = 0;
	while (p->x_map_dub < p->x_map)
	{
		p->y_map_dub = 0;
		while (p->y_map_dub < p->y_map)
		{
			insert_tetri(p, link);
			p->y_map_dub++;
		}
		p->x_map_dub++;
	}
}

void			search_coordinate(t_pointer *p)
{
	t_link		*link;

	link = (t_link*)malloc(sizeof(t_link));
	while (p->insert[p->in_x_dub])
	{
		p->in_y_dub = 0;
		while (p->insert[p->in_x_dub][p->in_y_dub] != '\0')
		{
			if (p->insert[p->in_x_dub][p->in_y_dub] == '*')
				p->add++;
			p->in_y_dub++;
		}
		p->in_x_dub++;
	}
	link->insert_player = 1;
	start_search(p, link);
	ft_printf("%d %d\n", p->x_out, p->y_out);
	free(link);
}
