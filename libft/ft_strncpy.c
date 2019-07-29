/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:43:41 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 21:23:04 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (n >= i)
	{
		while (i < n)
		{
			s1[i] = s2[j];
			if (s2[j] != '\0')
				j++;
			i++;
		}
		return (s1);
	}
	return (NULL);
}
