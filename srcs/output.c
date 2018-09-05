/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:27:10 by rbalbous          #+#    #+#             */
/*   Updated: 2018/05/03 14:35:08 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_conflict(t_lem *c, int i, int j, int k)
{
	int		l;
	int		path_to_del;

	l = -1;
	while (c->tmp[j] >= 0 && ++l < c->paths[c->tmp[j]][1] - 1)
	{
		if (c->paths[c->tmp[i]][k + 2] == c->paths[c->tmp[j]][l + 2])
		{
			if (c->paths[c->tmp[i]][1] <= c->paths[c->tmp[j]][1])
				path_to_del = j;
			else
				path_to_del = i;
			c->tmp[path_to_del] = -1;
		}
	}
}

void		get_conflicts(t_lem *c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (++i < c->nb_soluce + 1)
	{
		if (c->tmp[i] == -1)
			continue ;
		j = i;
		while (++j < c->nb_soluce + 1)
		{
			if (c->tmp[j] == -1)
				continue ;
			k = -1;
			while (c->tmp[i] >= 0 && ++k < c->paths[c->tmp[i]][1] - 1)
				check_conflict(c, i, j, k);
		}
	}
}

int			get_sub_sol(t_lem *c, int sol)
{
	int		index;
	int		ret;

	index = -1;
	ret = -1;
	while (++index < c->nb_paths)
	{
		if (c->paths[index][0] > sol)
		{
			ret = c->paths[index][0];
			break ;
		}
	}
	if (ret > sol + 10000)
		return (-1);
	return (ret % 10000);
}

void		get_output(t_lem *c, int sol, int index, int tmp_index)
{
	int		next_sol_ct;

	if (sol == c->sol_max)
	{
		get_conflicts(c);
		antflow(c);
		return ;
	}
	next_sol_ct = get_sub_sol(c, sol + 10000);
	if (next_sol_ct == -1)
	{
		c->tmp[tmp_index] = -1;
		get_output(c, sol + 10000, 0, tmp_index + 1);
		return ;
	}
	if (index == 0)
		while (c->paths[index][0] < sol + 10000)
			index++;
	while (next_sol_ct > 0)
	{
		c->tmp[tmp_index] = index;
		get_output(c, sol + 10000, 0, tmp_index + 1);
		index++;
		next_sol_ct--;
	}
}

int			output(t_lem *c)
{
	int			index;

	index = 0;
	if (!(c->result = (int *)ft_memalloc(sizeof(int) * (c->nb_soluce + 2))))
		display_error(MALLOC);
	if (!(c->tmp = (int *)ft_memalloc(sizeof(int) * (c->nb_soluce + 2))))
		display_error(MALLOC);
	c->result[0] = 0;
	while (index < c->paths[0][0] % 10000)
	{
		c->tmp[1] = index;
		get_output(c, 10000, index, 2);
		index++;
	}
	return (0);
}
