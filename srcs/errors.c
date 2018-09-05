/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:24:49 by rbalbous          #+#    #+#             */
/*   Updated: 2018/05/16 17:26:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		reset(t_lem *c, int k)
{
	int		i;

	i = 2;
	c->rooms[0].al_checked = 0;
	c->rooms[0].way_out = 0;
	while (i < c->nb_rooms)
	{
		if (k == 0)
		{
			c->rooms[i].dist = c->nb_rooms + 1;
			c->rooms[i].nb_sol = 0;
		}
		c->rooms[i].al_checked = 0;
		i++;
	}
}

int			check_path(t_lem *c, int path, int dist)
{
	int		index;

	index = 0;
	if (c->rooms[path].dist <= dist || path == 1)
		return (0);
	while (index < c->rooms[path].nb_links)
	{
		c->rooms[path].dist = dist;
		if (c->rooms[path].links[index] == 1)
			c->sol_max = 1;
		check_path(c, c->rooms[path].links[index], dist + 1);
		index++;
	}
	return (0);
}

int			remove_links(t_lem *c, int i)
{
	int		index;
	int		rooms_index;

	index = c->rooms[i].links[0];
	rooms_index = 0;
	while (rooms_index < c->rooms[index].nb_links)
	{
		if (c->rooms[index].links[rooms_index] == i)
		{
			if (rooms_index != c->rooms[index].nb_links)
			{
				rooms_index++;
				while (rooms_index < c->rooms[index].nb_links)
				{
					c->rooms[index].links[rooms_index - 1] =
					c->rooms[index].links[rooms_index];
					rooms_index++;
				}
				c->rooms[index].nb_links--;
				break ;
			}
		}
		rooms_index++;
	}
	return (rooms_index);
}

void		get_best_result(t_lem *c)
{
	int		i;

	i = 1;
	while (++i < c->nb_rooms)
	{
		c->rooms[i].way_out = 0;
		c->rooms[i].nb_sol = 0;
		c->rooms[i].dist = c->nb_rooms + 1;
		if (c->rooms[i].nb_links == 1)
		{
			c->rooms[i].nb_links--;
			if (remove_links(c, i) < i)
				i = 1;
		}
	}
	reset(c, 1);
	if (c->rooms[0].nb_links == 0 || c->rooms[1].nb_links == 0)
		display_error(LINK);
	check_path(c, c->rooms[c->nb_rooms].links[0], 0);
	if (c->sol_max == 0)
		display_error(LINK);
	c->rooms[1].dist = c->nb_rooms + 1;
}

void		check_links(t_lem *c)
{
	int		i;

	i = 0;
	if (c->flags & CHEAT)
		display(c, 1);
	while (i < c->rooms[0].nb_links)
	{
		if (c->rooms[0].links[i] == 1)
			display(c, 1);
		i++;
	}
	c->rooms[0].way_out = 0;
	c->rooms[0].nb_sol = 0;
	c->rooms[0].dist = c->nb_rooms + 1;
	c->rooms[1].dist = c->nb_rooms + 1;
	c->rooms[1].nb_sol = 0;
	get_best_result(c);
}
