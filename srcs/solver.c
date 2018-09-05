/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:09:20 by rbalbous          #+#    #+#             */
/*   Updated: 2018/06/12 16:56:16 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		*ft_memaccpy_special(t_lem *c, const void *src, int s)
{
	void	*dest;
	char	*tmp;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	tmp = (char *)src;
	while (tmp[i] && ft_ispace(tmp[i]))
		i++;
	while (tmp[i] && tmp[i] != s)
		i++;
	if (i > c->max_len)
		c->max_len = i;
	if (!tmp[i])
		return (NULL);
	if ((dest = ft_memalloc(i + 1)) == 0)
		return (NULL);
	ft_memcpy(dest, src, i);
	return (dest);
}

void		copy_to_result(t_lem *c, int **length)
{
	int		i;

	i = 0;
	while (i < c->nb_soluce + 1)
	{
		c->result[i] = c->tmp[i];
		i++;
	}
	i = 0;
	if (c->r_length)
		free(c->r_length);
	if (!(c->r_length = (int*)ft_memalloc(sizeof(int) * (c->solutions + 1))))
		display_error(MALLOC);
	while (i < c->solutions)
	{
		c->r_length[i] = (*length)[i];
		i++;
	}
}

int			solver_init(t_lem *c)
{
	int		nb_paths_max;

	nb_paths_max = 0;
	if (c->rooms[0].nb_links > c->rooms[1].nb_links)
		c->nb_soluce = c->rooms[0].nb_links;
	else
		c->nb_soluce = c->rooms[1].nb_links;
	c->rooms[0].al_checked = 1;
	c->nb_paths = 0;
	nb_paths_max = (c->nb_rooms - 1) * ((c->nb_rooms - 2) / 2);
	if (nb_paths_max == 0)
		nb_paths_max = c->nb_rooms - 1;
	if (!(c->paths = ft_memalloc(sizeof(int*) * (nb_paths_max + 2))))
		display_error(MALLOC);
	return (10000);
}

void		solver(t_lem *c)
{
	int		index;
	int		sol;

	index = -1;
	sol = solver_init(c);
	while (++index < c->nb_soluce)
	{
		sol = (index + 1) * 10000;
		c->sol_max = sol;
		reset(c, 1);
		if (algo(c, c->rooms[0].links[index], &sol) == 1)
		{
			get_path(c, index);
			if (index + 1 < c->rooms[0].nb_links)
			{
				reset(c, 0);
				c->rooms[0].dist = c->nb_rooms + 1;
				get_new_dist(c, c->rooms[c->nb_rooms].links[0], 0, index + 1);
			}
			c->rooms[1].dist = c->nb_rooms + 1;
		}
	}
	output(c);
}
