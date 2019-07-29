/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:54:01 by ashypilo          #+#    #+#             */
/*   Updated: 2019/04/20 14:54:53 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	void	getting_tetri(t_pointer *p)
{
	if (ft_strncmp(p->string, "Piece", 4) == 0)
	{
		if (p->insert != NULL)
			delete_insert(p);
		p->x_insert = ft_atoi(&p->string[5]);
		p->y_insert = ft_atoi(&p->string[7]);
		if (p->insert == NULL)
		{
			p->insert = (char**)malloc(sizeof(char*) * (p->x_insert + 1));
			p->insert[p->x_insert] = NULL;
		}
		p->get_insert = 1;
		p->i = 0;
	}
	else if (p->get_insert == 1)
	{
		p->insert[p->in_x_dub] = ft_strdup(p->string);
		p->in_x_dub++;
	}
}

static	void	getting_player_and_proportions(t_pointer *p)
{
	int			i;

	i = 0;
	if (ft_strcmp(p->string, "$$$ exec p1 : [./ashypilo.filler]") == 0)
	{
		p->player = 'O';
		p->player_second = 'X';
	}
	else if (ft_strcmp(p->string, "$$$ exec p2 : [./ashypilo.filler]") == 0)
	{
		p->player = 'X';
		p->player_second = 'O';
	}
	else if (ft_strncmp(p->string, "Plateau", 6) == 0)
	{
		p->x_map = ft_atoi(&p->string[7]);
		p->y_map = ft_atoi(&p->string[11]);
		p->map = (char**)malloc(sizeof(char*) * (p->x_map + 1));
		p->map[p->x_map] = NULL;
		p->int_map = (int**)malloc(sizeof(int*) * (p->x_map + 1));
		while (i < p->x_map)
			p->int_map[i++] = (int*)malloc(sizeof(int) * (p->y_map + 1));
		p->start = 0;
	}
}

static	void	ft_getting(t_pointer *p, int fd0)
{
	while (get_next_line(fd0, &p->string) > 0)
	{
		if (p->start == 1)
			getting_player_and_proportions(p);
		else if (ft_strncmp(p->string, "Piece", 4) == 0 || p->get_insert == 1)
			getting_tetri(p);
		else if (p->string[0] == '0' && p->string[3] == ' ')
		{
			p->map[p->i] = ft_strdup(&p->string[4]);
			p->i++;
		}
		if (p->in_x_dub == p->x_insert && p->x_insert != 0)
		{
			calculation(p);
			p->get_insert = 0;
			p->get_map = 0;
			p->in_x_dub = 0;
			delete_map(p);
			p->map = (char**)malloc(sizeof(char*) * (p->x_map + 1));
			p->map[p->x_map] = NULL;
		}
		free(p->string);
	}
}

int				main(int argc, char **argv)
{
	int			fd0;
	t_pointer	*p;

	fd0 = 0;
	p = (t_pointer*)malloc(sizeof(t_pointer));
	p->start = 1;
	p->get_map = 0;
	p->get_insert = 0;
	p->in_x_dub = 0;
	p->insert = NULL;
	p->i = 0;
	if (argc == 1)
		fd0 = 0;
	else if (argc == 2)
		fd0 = open(argv[1], O_RDONLY);
	ft_getting(p, fd0);
	delete_insert(p);
	free(p->map);
	p->map = NULL;
	delete_int_map(p);
	free(p);
	close(fd0);
	return (0);
}
