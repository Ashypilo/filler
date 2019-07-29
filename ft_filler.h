/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:42:44 by ashypilo          #+#    #+#             */
/*   Updated: 2019/04/20 15:15:31 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

# define BUFF_SIZE 64

typedef struct	s_pointer
{
	int			i;
	int			fd;
	int			get_map;
	int			**int_map;
	char		**map;
	char		**insert;
	char		*string;
	int			first_o;
	int			second_x;
	int			x_map;
	int			y_map;
	int			x_map_dub;
	int			y_map_dub;
	int			x_out;
	int			y_out;
	int			add_out;
	int			add;
	int			in_col;
	int			y_insert;
	int			x_insert;
	int			in_x_dub;
	int			in_y_dub;
	int			num_fill;
	int			stop;
	int			get_coord;
	int			start;
	int			get_insert;
	int			player;
	int			player_second;
}				t_pointer;

typedef struct	s_link
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			insert;
	int			out;
	int			x_out;
	int			y_out;
	int			insert_player;
	int			end;
}				t_link;

int				get_next_line(const int fd, char **line);
void			calculation(t_pointer *p);
void			search_coordinate(t_pointer *p);
void			output(char **arr);
void			delete_insert(t_pointer *p);
void			delete_map(t_pointer *p);
void			delete_int_map(t_pointer *p);

#endif
