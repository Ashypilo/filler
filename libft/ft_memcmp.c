/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:28:47 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/14 15:26:31 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*d1;
	char	*d2;
	size_t	i;

	d1 = (char *)s1;
	d2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (d1[i] != d2[i])
			return (((unsigned char)d1[i]) - ((unsigned char)d2[i]));
		i++;
	}
	return (0);
}
