/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:48:17 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 16:48:15 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = 0;
	if (s && f)
	{
		i = ft_strlen((char*)s);
		s2 = (char*)malloc(i + 1);
		if (s2 != NULL)
		{
			i = 0;
			while (s[i])
			{
				s2[i] = f(s[i]);
				i++;
			}
			s2[i] = '\0';
			return (s2);
		}
		return (NULL);
	}
	return (NULL);
}
