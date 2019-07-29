/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:56:11 by ashypilo          #+#    #+#             */
/*   Updated: 2018/11/20 17:16:55 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_numb(char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (j);
}

static int		ft_normin(char *s, char c, int j)
{
	while (s[j] != c & s[j] != '\0')
		j++;
	return (j);
}

static char		*ft_separator(char *s, char c, int i)
{
	int		j;
	int		k;
	char	*out1;

	j = 0;
	k = i;
	while (s[i] != c && s[i])
	{
		j++;
		i++;
	}
	out1 = (char*)malloc(sizeof(char) * (j + 1));
	if (out1 == NULL)
		return (NULL);
	j = 0;
	while (k < i)
	{
		out1[j] = s[k];
		k++;
		j++;
	}
	out1[j] = '\0';
	return (out1);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		k;
	char	**out;

	k = 0;
	if (s == NULL)
		return (NULL);
	j = ft_numb((char*)s, c);
	out = (char**)malloc(sizeof(char*) * (j + 1));
	if (out == NULL)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c)
			j++;
		else
		{
			out[k] = ft_separator((char*)s, c, j);
			j = ft_normin((char*)s, c, j);
			k++;
		}
	}
	out[k] = NULL;
	return (out);
}
