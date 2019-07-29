/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:17:23 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 15:26:53 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	i = 0;
	if (n > 0)
		i = n;
	else if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
			i = 2147483648;
		else
			i = n * -1;
		n = 0;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + 48);
	}
	else
		ft_putchar(i + 48);
}
