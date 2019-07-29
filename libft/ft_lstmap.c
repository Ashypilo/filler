/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:16:48 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/20 16:39:24 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new1;
	t_list *out;

	if (lst == NULL || !f)
		return (NULL);
	new1 = f(lst);
	out = new1;
	while (lst->next)
	{
		new1->next = f(lst->next);
		new1 = new1->next;
		lst = lst->next;
	}
	if (out == NULL)
		return (NULL);
	return (out);
}
