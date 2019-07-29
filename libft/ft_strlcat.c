/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:18:46 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/20 16:23:15 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *scat1, const char *scat2, size_t size)
{
	size_t out;
	size_t pot;
	size_t mane;

	out = 0;
	pot = 0;
	mane = ft_strlen(scat1);
	while (scat1[out] && out < size)
		out++;
	if (out >= size)
		return (size + ft_strlen(scat2));
	while (scat2[pot] && pot < (size - mane - 1))
	{
		scat1[out + pot] = scat2[pot];
		pot++;
	}
	scat1[out + pot] = '\0';
	return (out + ft_strlen(scat2));
}
