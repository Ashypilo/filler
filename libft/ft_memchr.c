/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:08:24 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/19 16:51:02 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s1, int c, size_t n)
{
	int				i;
	unsigned char	*d1;

	d1 = (unsigned char*)s1;
	i = 0;
	while ((size_t)i < n)
	{
		if (d1[i] == (unsigned char)c)
			return (d1 + i);
		i++;
	}
	return (NULL);
}
