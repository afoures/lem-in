/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:13:31 by rbalbous          #+#    #+#             */
/*   Updated: 2018/06/05 17:07:55 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			algo(t_lem *c, int path, int *sol)
{
	int		index;

	index = -1;
	while (++index < c->rooms[path].nb_links)
	{
		if (c->rooms[c->rooms[path].links[index]].dist <= c->rooms[path].dist)
			continue ;
		if (c->rooms[path].links[index] == 1)
		{
			(*sol)++;
			if (c->rooms[path].way_out < *sol
				|| !c->rooms[path].way_out)
				c->rooms[path].way_out = *sol;
			c->rooms[1].way_out = *sol;
			return (1);
		}
		if (algo(c, c->rooms[path].links[index], sol)
		&& c->rooms[path].way_out < *sol)
		{
			c->rooms[path].way_out = *sol;
		}
	}
	return (c->rooms[path].way_out == *sol || path == 0);
}

int			recur_goood(t_lem *c, int path, int sol)
{
	int		i;
	int		tmp;

	i = 0;
	while (i < c->rooms[path].nb_links)
	{
		if (c->rooms[path].links[i] == 1)
		{
			c->rooms[c->rooms[path].links[i]].way_out = sol - 1;
		}
		if (c->rooms[c->rooms[path].links[i]].way_out < sol
		&& c->rooms[c->rooms[path].links[i]].way_out > c->sol_max)
		{
			tmp = c->rooms[c->rooms[path].links[i]].way_out;
			if (c->rooms[path].way_out == sol || tmp > c->rooms[path].way_out)
				c->rooms[path].way_out = tmp;
		}
		i++;
	}
	return (1);
}

int			all_paths(t_lem *c, int path, int sol)
{
	int		index;

	index = -1;
	while (++index < c->rooms[path].nb_links)
	{
		if (c->rooms[c->rooms[path].links[index]].dist <= c->rooms[path].dist)
			continue ;
		if (c->rooms[path].links[index] == 1
		|| c->rooms[c->rooms[path].links[index]].way_out == sol)
		{
			c->paths[c->nb_paths][2 + c->paths[c->nb_paths][1]] = path;
			c->paths[c->nb_paths][1]++;
			if (c->rooms[path].links[index] == 1
			|| all_paths(c, c->rooms[path].links[index], sol) == 1)
				return (recur_goood(c, path, sol));
		}
	}
	return (0);
}

int			get_path(t_lem *c, int index)
{
	int		curr_sol;

	curr_sol = c->rooms[c->rooms[0].links[index]].way_out;
	while (curr_sol > c->sol_max)
	{
		if (!c->paths[c->nb_paths])
		{
			if (!(c->paths[c->nb_paths] =
			(int*)ft_memalloc(sizeof(int) * (c->nb_rooms + 1))))
				display_error(MALLOC);
		}
		else
			ft_bzero(c->paths[c->nb_paths], sizeof(int) * (c->nb_rooms + 1));
		c->paths[c->nb_paths][0] = curr_sol;
		c->paths[c->nb_paths][1] = 0;
		reset(c, 1);
		if (all_paths(c, c->rooms[0].links[index], curr_sol) == 1)
		{
			c->paths[c->nb_paths][2 + c->paths[c->nb_paths][1]] = 1;
			c->paths[c->nb_paths][1]++;
			c->nb_paths++;
			curr_sol--;
		}
	}
	return (0);
}

int			get_new_dist(t_lem *c, int path, int dist, int start)
{
	int		index;

	index = start;
	if (c->rooms[path].dist <= dist || path == 1)
		return (0);
	while (index < c->rooms[path].nb_links)
	{
		c->rooms[path].dist = dist;
		get_new_dist(c, c->rooms[path].links[index], dist + 1, 0);
		index++;
	}
	return (0);
}
