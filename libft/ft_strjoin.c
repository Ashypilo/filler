/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:54:15 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 16:42:48 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*origin;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (s1 || s2)
	{
		i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		origin = (char *)malloc(i + 1);
		if (origin != NULL)
		{
			ft_bzero(origin, i);
			origin = ft_strcat(origin, (char *)s1);
			origin = ft_strcat(origin, (char *)s2);
			origin[i] = '\0';
			return (origin);
		}
	}
	return (NULL);
}
