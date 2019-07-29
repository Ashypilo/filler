/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:41:32 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/20 17:56:56 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_link_string
{
	char	*flaggs;
	char	f_plus;
	char	f_minus;
	char	f_zero;
	char	f_space;
	char	f_hash;
	char	*size;
	char	*type_string;
	char	type_c;
	char	type;
	char	zero;
	char	*scpdiouxf;
	char	*fresh_dub;
	char	*fresh;
	char	*output;
	char	*output_head;
	char	width_big_acc;
	char	format;
}				t_char;

typedef struct	s_link_int
{
	int			type_system;
	int			not_acc;
	int			characters;
	int			i_arg;
	int			k_min;
	int			zero_minus;
	long double	type_float;
	long double	f;
	long double	f_f;
	intmax_t	width;
	intmax_t	accuracy;
	intmax_t	argument;
	__int128_t	k;
	__int128_t	n_k;
	intmax_t	ac;
	intmax_t	j;
	intmax_t	op_ac;
	uintmax_t	i;
	intmax_t	string_value;
	intmax_t	arr_string_d;
	intmax_t	size_flagg;
	intmax_t	dub_arg;
	intmax_t	minus_i;
	intmax_t	plus;
	intmax_t	rev_o;
}				t_int;

int				ft_f_oktotop(t_char *link, t_int *poin, intmax_t i);
int				ft_flagg_zero(t_char *link, t_int *poin, intmax_t i);
void			ft_string_float(t_char *link, t_int *poin);
int				ft_output(t_char *link, t_int *point, intmax_t i);
void			ft_dicsf(t_char *pointer, t_int *poin, va_list ap);
char			*ft_strdup(const char *src);
int				ft_atoi(const char *s1);
void			*ft_bzero(void *s1, size_t n);
int				ft_isdigit(int n);
void			ft_putchar(char c);
size_t			ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *s1, int n);
void			ft_float_conversion(t_char *link, t_int *poin);
int				ft_format(t_char *pointer, t_int *point, va_list ap);
int				ft_printf(const char *format, ...);
int				ft_type(t_char *pointer, t_int *point);
char			*ft_itoa_base(intmax_t n);

#endif
