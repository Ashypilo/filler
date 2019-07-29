/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 20:43:09 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/20 16:17:03 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_inta(unsigned long n, int k)
{
	unsigned long out;

	out = 0;
	if (n == 2147483648 && k == -1)
		out = -2147483648;
	else if (n > 9223372036854775807 && k == -1)
		out = 0;
	else if (n >= 9223372036854775807)
		out = -1;
	else
		out = n * k;
	return (out);
}

static int	ft_kat(const char *s1)
{
	int k;
	int j;

	j = 0;
	k = 1;
	while (*s1 < 48 || *s1 > 57)
	{
		if (*s1 == '-')
		{
			k = -1;
			j++;
			s1++;
			if (*s1 == '+' || *s1 == '-' || *s1 < 48)
				j++;
		}
		else if (*s1 == '+')
		{
			k = 1;
			j++;
		}
		s1++;
	}
	if (j > 1)
		return (0);
	return (k);
}

int			ft_atoi(const char *s1)
{
	int				k;
	int				out;
	unsigned long	n;

	out = 0;
	k = ft_kat(s1);
	n = 0;
	while (*s1 == ' ' || *s1 == '\t' || *s1 == '-' || *s1 == '+' ||
	*s1 == '\n' || *s1 == '\v' || *s1 == '\f' || *s1 == '\r')
	{
		s1++;
	}
	while (*s1 >= 48 && *s1 <= 57)
	{
		n = n * 10 + *s1 - 48;
		s1++;
	}
	out = ft_inta(n, k);
	return (out);
}
