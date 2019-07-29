/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:21:15 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 18:27:40 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	j = 0;
	i = ft_strlen((char *)s2);
	if (i == 0 || (ft_strcmp((char *)s1, (char *)s2) == 0))
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			while ((s1[i] == s2[j]) && (s2[j] != '\0' || s1[i] != '\0'))
			{
				i++;
				j++;
			}
			i = i - j;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
			j = 0;
		}
		i++;
	}
	return (0);
}
