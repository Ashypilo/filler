/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:37:47 by ashypilo          #+#    #+#             */
/*   Updated: 2019/04/20 14:58:23 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static	int			ft_rev_out(char **stat_fd, char **line_out)
{
	char			*stat_line;
	char			*stat;
	int				n;

	stat_line = *stat_fd;
	stat = *stat_fd;
	if (ft_strlen(stat_line) == 0)
		return (0);
	stat_line = ft_strchr(stat_line, '\n');
	if (stat_line == NULL)
	{
		*line_out = ft_strdup(*stat_fd);
		*stat_fd = ft_strnew(0);
	}
	else
	{
		n = ft_strlen(*stat_fd) - ft_strlen(stat_line);
		*line_out = ft_strncat(ft_strnew(n), *stat_fd, n);
		stat_line++;
		*stat_fd = ft_strdup(stat_line);
	}
	free(stat);
	return (1);
}

static	char		*ft_reading(const int fd, char *buf, char **stat, int rev)
{
	char			*string;

	while ((rev = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rev] = '\0';
		string = stat[fd];
		stat[fd] = ft_strjoin(string, buf);
		if (ft_strchr(buf, '\n'))
		{
			free(string);
			break ;
		}
		free(string);
	}
	return (stat[fd]);
}

int					get_next_line(const int fd, char **line)
{
	int				rev;
	char			buf[BUFF_SIZE + 1];
	static	char	*stat[4096];

	rev = 0;
	if (fd == -1 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	if (stat[fd] == NULL)
		stat[fd] = ft_strnew(0);
	if (ft_strchr(stat[fd], '\n') == NULL)
		stat[fd] = ft_reading(fd, buf, stat, rev);
	if (ft_rev_out((&stat[fd]), line) == 1)
		return (1);
	if (rev == -1)
		return (-1);
	free(stat[fd]);
	stat[fd] = NULL;
	return (0);
}
