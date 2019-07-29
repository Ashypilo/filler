/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:03:56 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/15 16:30:53 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*crs;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if ((crs = (char*)malloc(sizeof(char) * (i + 1))))
	{
		while (j < i)
		{
			crs[j] = src[j];
			j++;
		}
		crs[j] = '\0';
		return (crs);
	}
	return (0);
}
