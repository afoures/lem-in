/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antflow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 14:22:59 by rbalbous          #+#    #+#             */
/*   Updated: 2018/06/05 16:01:08 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ret_max(t_lem *c, int stop, int **length)
{
	int		index;
	int		max;
	int		tmp_index;

	index = 0;
	max = 0;
	tmp_index = 1;
	while (index < stop && tmp_index < c->nb_soluce + 1)
	{
		if (c->tmp[tmp_index] != -1 && c->tmp[tmp_index] < c->nb_paths)
		{
			if (max < (*length)[index] + (c->paths[c->tmp[tmp_index]][1] - 1))
				max = (*length)[index] + (c->paths[c->tmp[tmp_index]][1] - 1);
			index++;
		}
		tmp_index++;
	}
	return (max);
}

void		ret_left(int sum, int max, int stop, int **length)
{
	int		index;

	index = 0;
	max += stop * (max == 0);
	while (sum != 0)
	{
		(*length)[index]++;
		index++;
		if (index == max)
			index = 0;
		sum += (sum > 0) * -2 + 1;
	}
}

void		add_left(t_lem *c, int left, int stop, int **length)
{
	int		sum;
	int		index;
	int		max;

	sum = 0;
	index = 0;
	while (index < stop)
	{
		if ((*length)[index++] < 0)
		{
			sum += (*length)[index];
			if (max == 0)
				max = index + 1;
		}
	}
	sum += left;
	ret_left(sum, max, stop, length);
	c->tmp[0] = ret_max(c, stop, length);
	if (c->result[0] > c->tmp[0] || c->result[0] == 0)
	{
		c->solutions = stop;
		copy_to_result(c, length);
	}
}

void		init_length(t_lem *c, int sum, int r_sol, int **length)
{
	int		index;
	int		l_index;

	index = 0;
	l_index = 0;
	while (++index < c->nb_soluce + 1)
	{
		if (c->tmp[index] == -1)
			continue ;
		(*length)[l_index] = (sum / r_sol) - (c->paths[c->tmp[index]][1]);
		l_index++;
	}
}

void		antflow(t_lem *c)
{
	int		index;
	int		sum;
	int		r_sol;
	int		*length;

	sum = c->ants;
	index = 0;
	r_sol = c->nb_soluce;
	while (++index < c->nb_soluce + 1)
	{
		if (c->tmp[index] == -1)
		{
			r_sol--;
			continue ;
		}
		sum += c->paths[c->tmp[index]][1];
	}
	if (!(length = (int*)ft_memalloc(sizeof(int) * (r_sol + 1))))
		display_error(MALLOC);
	init_length(c, sum, r_sol, &length);
	add_left(c, sum % r_sol, r_sol, &length);
	free(length);
}
