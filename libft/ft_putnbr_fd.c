/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:39:31 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 15:29:36 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int i;

	i = 0;
	if (n > 0)
		i = n;
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
			i = 2147483648;
		else
			i = n * -1;
		n = 0;
	}
	if (i > 9)
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd(i % 10 + 48, fd);
	}
	else
		ft_putchar_fd(i + 48, fd);
}
