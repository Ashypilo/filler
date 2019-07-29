/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:23:50 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/20 16:32:54 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*d2;

	d1 = (unsigned char*)s1;
	d2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		d1[i] = d2[i];
		if (d2[i] == (unsigned char)c)
			return (d1 + i + 1);
		i++;
	}
	return (NULL);
}
