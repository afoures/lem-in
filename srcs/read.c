/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:33:18 by afoures           #+#    #+#             */
/*   Updated: 2018/06/05 16:01:43 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	*create_new_data(t_file *file)
{
	char *tmp;

	tmp = NULL;
	if (!(tmp = (char *)ft_memalloc(sizeof(char) * file->size)))
		display_error(MALLOC);
	ft_memcpy(tmp, file->data, file->cursor);
	free(file->data);
	return (tmp);
}

int			read_file(t_file *file)
{
	char	*line;
	int		ret;
	int		len;

	len = 0;
	line = NULL;
	while ((ret = get_next_line(file->fd, &line)) > 0)
	{
		if ((len = check_valid(line)) < 0)
			break ;
		if (file->cursor + len >= file->size)
		{
			file->size *= 2;
			file->data = create_new_data(file);
		}
		ft_memcpy(file->data + file->cursor, line, len);
		free(line);
		file->data[file->cursor + len] = '\n';
		file->cursor += len + 1;
	}
	free(line);
	file->data[file->cursor] = '\0';
	if (ret < 0)
		display_error(READ);
	return (len);
}
