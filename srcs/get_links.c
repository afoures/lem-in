/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:35:56 by afoures           #+#    #+#             */
/*   Updated: 2018/05/16 17:31:05 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_room_id(t_lem *c, int room)
{
	int		id;
	char	*ok;
	int		skip;

	id = 0;
	skip = 0;
	ok = NULL;
	while (c->str[c->str_index + skip] && c->str[c->str_index + skip] != '-'
			&& c->str[c->str_index + skip] != '\n')
		skip++;
	while (c->rooms[id].name)
	{
		ok = ft_strnstr(c->str + c->str_index, c->rooms[id].name, skip);
		if (ok && skip == (int)ft_strlen(c->rooms[id].name))
		{
			if ((!room && c->str[c->str_index + skip] != '-')
				|| (room && c->str[c->str_index + skip] != '\n'))
				display_error(BAD_NAME);
			c->str_index += skip + 1 * (c->str[c->str_index + skip] == '-');
			return (id);
		}
		id++;
	}
	return (-1);
}

static int		check_link(t_lem *c, int room1, int room2)
{
	int		i;

	i = 0;
	while (c->rooms[room1].links[i])
	{
		if (c->rooms[room1].links[i] == room2)
			return (-1);
		i++;
	}
	i = 0;
	while (c->rooms[room2].links[i])
	{
		if (c->rooms[room2].links[i] == room1)
			return (-1);
		i++;
	}
	return (0);
}

void			get_pipes(t_lem *c)
{
	int		room1;
	int		room2;

	while (c->str[c->str_index])
	{
		if (c->str[c->str_index] != '#')
		{
			room1 = get_room_id(c, 0);
			room2 = get_room_id(c, 1);
			if (room1 < 0 || room2 < 0 || room1 == room2)
				break ;
			if (!(check_link(c, room1, room2)))
			{
				c->rooms[room1].links[c->rooms[room1].nb_links++] = room2;
				c->rooms[room2].links[c->rooms[room2].nb_links++] = room1;
			}
		}
		else
			while (c->str[c->str_index] != '\n')
				c->str_index++;
		c->str_index++;
	}
}
