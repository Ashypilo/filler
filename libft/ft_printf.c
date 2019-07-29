/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:40:59 by ashypilo          #+#    #+#             */
/*   Updated: 2019/03/21 19:50:03 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ac_wid(const char *format, t_char *link, t_int *poin)
{
	if (ft_isdigit(*format))
	{
		poin->width = (uintmax_t)ft_atoi((char*)format);
		while (ft_isdigit(*format) && *format != '\0')
			format++;
	}
	if (*format == '.')
	{
		format++;
		poin->accuracy = 0;
		if (ft_isdigit(*format))
		{
			poin->accuracy = (uintmax_t)ft_atoi((char*)format);
			link->zero = '.';
		}
		while (ft_isdigit(*format) && *format != '\0')
			format++;
		poin->not_acc = 1;
	}
	return ((char*)format);
}

static char		*ft_f_start(const char *format, t_char *link, t_int *poin)
{
	while ((*format == '-' || *format == '+' || *format == ' ' ||
	*format == '0' || *format == '#') && *format != '\0')
	{
		if (*format == '-')
			link->f_minus = *format++;
		if (*format == '+')
			link->f_plus = *format++;
		if (*format == ' ')
			link->f_space = *format++;
		if (*format == '#')
			link->f_hash = *format++;
		if (*format == '0')
			link->f_zero = *format++;
	}
	if (ft_isdigit(*format) || *format == '.')
		format = ft_ac_wid(format, link, poin);
	if (*format == 'h' || *format == 'l' || *format == 'L' ||
		*format == 'j' || *format == 'z')
	{
		link->size[0] = *format++;
		if (*format == 'h')
			link->size[1] = *format++;
	}
	return ((char*)format);
}

static char		*up(const char *format, t_char *link, t_int *poin, va_list ap)
{
	while (*format == '-' || *format == '+' || *format == ' ' ||
	*format == '0' || *format == '#' || *format == '.' ||
	*format == 'h' || *format == 'l' || *format == 'L' ||
	*format == 'j' || *format == 'z' || (*format > 47 && *format < 58))
		format = ft_f_start(format, link, poin);
	if (ft_strchr(link->scpdiouxf, (int)*format) != 0)
	{
		link->type = *format;
		poin->characters = poin->characters + ft_format(link, poin, ap);
	}
	else if (*format != '\0')
	{
		poin->characters = poin->characters + ft_format(link, poin, ap);
		ft_putchar(*format);
		poin->characters++;
	}
	return ((char*)format);
}

static char		*flag(const char *format, t_int *poin, va_list ap)
{
	t_char		*link;

	link = (t_char*)malloc(sizeof(t_char));
	link->scpdiouxf = ft_strdup("%scpdiouxXf");
	link->size = (char*)malloc(sizeof(char) * 2);
	ft_bzero(link->size, 2);
	poin->width = 0;
	poin->accuracy = 0;
	poin->not_acc = 0;
	link->type_string = 0;
	link->type = 0;
	link->f_minus = '\0';
	link->f_plus = '\0';
	link->f_space = '\0';
	link->f_hash = '\0';
	link->f_zero = '\0';
	format = up(format, link, poin, ap);
	free(link->scpdiouxf);
	free(link);
	return ((char*)format);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_int		*poin;
	intmax_t	i;

	poin = (t_int*)malloc(sizeof(t_int));
	poin->characters = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		while (*format == '%')
		{
			format = flag(++format, poin, ap);
			if (*format != '\0')
				format++;
		}
		if (*format != '\0')
		{
			ft_putchar(*format++);
			poin->characters++;
		}
	}
	va_end(ap);
	i = poin->characters;
	free(poin);
	return (i);
}
