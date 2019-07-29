/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:58:41 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/16 17:59:09 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *copy;

	copy = (t_list*)malloc(sizeof(t_list));
	if (copy == NULL)
		return (NULL);
	else if (content == NULL)
	{
		copy->content = NULL;
		copy->content_size = 0;
	}
	else
	{
		copy->content = malloc(sizeof(copy->content) * content_size);
		if (copy->content == NULL)
			return (NULL);
		copy->content = ft_memcpy(copy->content, (void*)content, content_size);
		copy->content_size = content_size;
	}
	copy->next = NULL;
	return (copy);
}
