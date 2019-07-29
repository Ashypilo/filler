/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:53:14 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 18:30:48 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	if (s)
	{
		if (s[start] || s[len])
		{
			s2 = (char *)malloc(len + 1);
			if (s2)
			{
				i = 0;
				while (i < len)
				{
					s2[i] = (char)s[start];
					i++;
					start++;
				}
				s2[i] = '\0';
				return (s2);
			}
		}
	}
	return (NULL);
}
