/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:08:32 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/19 14:53:58 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		getendline(char *store, char **line, char *tmp)
{
	if ((*line = ft_strsub(store, 0, tmp - store)) == NULL)
		return (-1);
	ft_strcpy(store, tmp + 1);
	return (1);
}

int		last_lines(char **store, char **line)
{
	if ((*line = ft_strsub(*store, 0, ft_strlen(*store))) == 0)
		return (-1);
	if (*line[0] != 0)
	{
		ft_strclr(*store);
		return (1);
	}
	else
		ft_strdel(store);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*store[OPEN_MAX];
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (store[fd] == NULL)
	{
		if ((store[fd] = malloc(1)) == NULL)
			return (-1);
		store[fd][0] = 0;
	}
	if ((tmp = ft_strchr(store[fd], '\n')) != NULL)
		return (getendline(store[fd], line, tmp));
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		store[fd] = ft_strjoinfree(store[fd], buf, 1);
		if ((tmp = ft_strchr(store[fd], '\n')) != NULL)
			return (getendline(store[fd], line, tmp));
	}
	if (ret == -1)
		return (-1);
	return (last_lines(&store[fd], line));
}
