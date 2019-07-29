/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 09:08:19 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 15:36:56 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	int	index;

	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			ft_putchar(str[index]);
			index++;
		}
	}
}
