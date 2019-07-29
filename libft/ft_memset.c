/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:20:06 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 15:20:26 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s1, int c, size_t n)
{
	size_t	i;
	char	*d1;

	d1 = (char *)s1;
	i = 0;
	while (i < n)
	{
		d1[i] = c;
		i++;
	}
	return (d1);
}
