/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:54:50 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/19 19:19:34 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	while (i < n && s1[i])
	{
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		j = 0;
		if (s1[i] == s2[j])
		{
			while (i < n && s2[j] && s1[i] == s2[j])
			{
				i++;
				j++;
			}
			i = i - j;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (0);
}
