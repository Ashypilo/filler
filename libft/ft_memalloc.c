/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:07:30 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 19:08:41 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	if (size)
	{
		s1 = (unsigned char*)malloc(size);
		if (s1 != NULL)
		{
			while (i < size)
			{
				s1[i] = '\0';
				i++;
			}
			return ((void*)s1);
		}
	}
	return (NULL);
}
