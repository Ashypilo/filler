/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:28:35 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/14 15:25:49 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*d1;
	char	*d2;

	d1 = (char *)s1;
	d2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		d1[i] = d2[i];
		i++;
	}
	return (d1);
}
