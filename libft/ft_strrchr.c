/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:04:29 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/16 16:30:22 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s1, int n)
{
	int i;

	i = ft_strlen((char*)s1);
	while (i >= 0)
	{
		if (s1[i] == n)
			return ((char*)s1 + i);
		i--;
	}
	if (n == '\0')
		return ((char*)s1 + i);
	return (NULL);
}
