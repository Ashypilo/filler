/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:14:45 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/20 15:41:39 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = (char*)malloc(size + 1);
	if (s1 == NULL)
		return (s1);
	ft_bzero(s1, size + 1);
	return (s1);
}
