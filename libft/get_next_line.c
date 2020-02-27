/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:27:00 by sluhtala          #+#    #+#             */
/*   Updated: 2019/11/15 19:20:28 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include "libft.h"

/*
**Saveline saves line and creates a new str starting from the next line.
*/

char	*saveline(char **line, char **fdbuf)
{
	char	*new;
	int		linelen;
	int		endlen;

	linelen = 0;
	endlen = 0;
	while ((*fdbuf)[linelen] != '\n' && (*fdbuf)[linelen] != '\0')
		linelen++;
	*line = ft_strsub(*fdbuf, 0, linelen);
	if ((*fdbuf)[linelen] == '\0')
		new = ft_strnew(1);
	else
	{
		while ((*fdbuf)[linelen + endlen + 1])
			endlen++;
		new = ft_strsub(*fdbuf, linelen + 1, endlen);
	}
	free(*fdbuf);
	return (new);
}

int		check_line(char **fdbuf, int fd)
{
	int i;

	i = 0;
	while (fdbuf[fd][i] != '\n' && fdbuf[fd][i])
		i++;
	if (fdbuf[fd][i] == '\n')
		return (1);
	return (0);
}

/*
**Read_help tests if there is lnbreak. Then reads file to buffer.
*/

int		read_help(char **fdbuf, int fd, char *buf)
{
	int		ret;
	char	*temp;

	if (check_line(fdbuf, fd) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(fdbuf[fd], buf);
		free(fdbuf[fd]);
		fdbuf[fd] = temp;
		if (!fdbuf[fd])
			return (-1);
		if (check_line(fdbuf, fd) == 1 && ret > 0)
			break ;
	}
	if (ret == 0 && ft_strlen(fdbuf[fd]) > 0)
		return (1);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*fdbuf[4864];
	int			ret;

	if (fd < 0 || !line || fd >= 4864 || BUFF_SIZE <= 0)
		return (-1);
	if (!fdbuf[fd])
	{
		if (!(fdbuf[fd] = ft_strnew(1)))
			return (-1);
	}
	if ((ret = read_help(fdbuf, fd, buf)) == -1)
		return (-1);
	if (ret > 0)
	{
		if (!(fdbuf[fd] = saveline(line, &(fdbuf[fd]))))
			return (-1);
	}
	if (ret == 0)
		return (0);
	return (1);
}
