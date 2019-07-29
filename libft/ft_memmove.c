/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:34:13 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 15:07:56 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*d1;
	char	*d2;

	d1 = ((char *)s1);
	d2 = ((char *)s2);
	i = 0;
	if (s2 > s1)
	{
		while (i < n)
		{
			d1[i] = d2[i];
			i++;
		}
		return (d1);
	}
	n--;
	while ((int)n >= 0)
	{
		d1[n] = d2[n];
		n--;
	}
	return (d1);
}
