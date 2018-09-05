/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:41:02 by afoures           #+#    #+#             */
/*   Updated: 2018/06/12 17:06:36 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			create_tmp_room(t_lem *c)
{
	c->rooms[c->nb_rooms].name = ft_strdup("tmp_room");
	if (!(c->rooms[c->nb_rooms].links = ft_memalloc(sizeof(int) * (2))))
		display_error(MALLOC);
	c->rooms[c->nb_rooms].links[0] = 0;
	c->rooms[c->nb_rooms].nb_links = 1;
	return (1);
}

static int			create_rooms(t_lem *c, t_lstname *first)
{
	int			index;
	t_lstname	*tmp;
	int			i;

	if (!(c->rooms = (t_room *)ft_memalloc(sizeof(t_room) * (c->nb_rooms + 4))))
		display_error(MALLOC);
	index = 2;
	tmp = first;
	while (tmp)
	{
		i = (tmp->type - 1) * (tmp->type > 0) + index * !tmp->type;
		if (c->rooms[i].name)
			return (-1);
		if (!(c->rooms[i].links = ft_memalloc(sizeof(int) * (c->nb_rooms + 1))))
			display_error(MALLOC);
		c->rooms[i].name = ft_strdup(tmp->name);
		c->rooms[i].nb_links = 0;
		index += !tmp->type;
		tmp = tmp->next;
	}
	index += create_tmp_room(c);
	c->rooms[index].name = NULL;
	free_lst(first);
	return (0);
}

static int			get_room_type(t_lem *c, int type)
{
	int		tmp;

	tmp = type;
	tmp += (!(ft_strncmp(c->str + c->str_index + 2, "start", 5)))
		+ 2 * (!(ft_strncmp(c->str + c->str_index + 2, "end", 3)));
	if (type != 0 && tmp != type)
		display_error(COMMAND);
	return (tmp);
}

static t_lstname	*fill_room(t_lstname *first, t_lem *c)
{
	static int	tmp = 0;
	t_lstname	*elem;

	if (c->str[c->str_index] == '#' && c->str[c->str_index + 1]
	&& c->str[c->str_index + 1] == '#')
		tmp = get_room_type(c, tmp);
	else if (c->str[c->str_index] != '#')
	{
		if (c->str[c->str_index] == 'L')
			display_error(BAD_NAME);
		if (check_hyphen(c) && first && (first->brk = 1))
			return (first);
		if (!(elem = ft_memalloc(sizeof(t_lstname) + 1)))
			display_error(MALLOC);
		if (!(elem->name = ft_memaccpy_special(c, c->str + c->str_index, ' ')))
			display_error(INFO" or "MALLOC);
		elem->type = tmp;
		elem->brk = 0;
		elem->next = first;
		first = elem;
		c->nb_rooms++;
		tmp = 0;
	}
	return (first);
}

int					get_rooms(t_lstname *first, t_lem *c)
{
	while (c->str[c->str_index] && c->str[c->str_index] != '\n')
		c->str_index++;
	c->str_index++;
	c->nb_rooms = 0;
	c->max_len = 0;
	while (c->str[c->str_index])
	{
		first = fill_room(first, c);
		if (first && ft_strchr(first->name, '-'))
			display_error(BAD_NAME);
		if (first && first->brk == 1)
			break ;
		check_valid_coord(c);
		c->str_index++;
	}
	create_rooms(c, first);
	if (!c->rooms[0].name || !c->rooms[1].name)
		display_error(NO_S_E);
	if (!c->str[c->str_index])
		display_error(INFO);
	return (0);
}
