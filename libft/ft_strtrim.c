/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:55:22 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/18 16:51:37 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_number(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
	{
		j++;
		if (s[j] == '\0')
			return (j);
	}
	while (s[j])
	{
		i++;
		j++;
	}
	while (s[j] == '\0' || s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		j--;
		i--;
	}
	return (i);
}

static char		*ft_out(char *out, char *s, int i)
{
	int	k;
	int	j;

	k = 0;
	j = 0;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (k <= i)
	{
		out[k] = s[j];
		k++;
		j++;
	}
	out[k] = '\0';
	return (out);
}

char			*ft_strtrim(char const *s)
{
	int	i;
	int	j;
	char*out;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	else if (s)
	{
		i = ft_number((char*)s);
		out = (char*)malloc(i + 2);
		if (out != NULL)
		{
			out = ft_out(out, (char*)s, i);
			return (out);
		}
	}
	return (NULL);
}
