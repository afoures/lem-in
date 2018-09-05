/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lmatador.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:21:12 by afoures           #+#    #+#             */
/*   Updated: 2018/06/05 16:16:57 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*create_lmatador(t_lem *c)
{
	int		i;
	int		len;
	int		max;
	char	*str;

	i = 0;
	len = 0;
	max = 0;
	while (++i < c->nb_soluce + 1)
	{
		if (c->tmp[i] == -1)
			continue ;
		if (len < c->paths[c->tmp[i]][1])
			len = c->paths[c->tmp[i]][1];
	}
	len += 1 * (c->nb_soluce == 0);
	if (!(str = (char *)ft_memalloc(sizeof(char)
		* ((c->max_len + 4 + c->antlen) * c->ants * len * 2000 + 1))))
		display_error(MALLOC);
	return (str);
}

int		fill_lmatador3(t_lem *c, t_display *disp, char *str, int i)
{
	i += ft_sprintf(str + i, "\n");
	disp->max = c->ants;
	if (!(c->flags & CHEAT))
	{
		while (disp->cur < disp->max)
		{
			i += print_colored_text2(c, str + i, disp);
			disp->cur++;
		}
		ft_sprintf(str + i - 1, "\n");
		return (i);
	}
	i += print_colored_text2(c, str + i, disp);
	disp->cur++;
	while (disp->cur < disp->max + 1)
	{
		i += print_colored_text2(c, str + i, disp);
		disp->cur++;
	}
	i += ft_sprintf(str + i - 1, "\n");
	return (i);
}

int		fill_lmatador2(t_lem *c, t_display *disp, char *str, int i)
{
	if (disp->turns[disp->cur] <= disp->id_turn && disp->turns[disp->cur] != -1
	&& (disp->stock[disp->cur] == 0 || disp->stock[disp->cur] == disp->path))
	{
		if (disp->stock[disp->cur] == 0 && c->r_length[disp->i_length] > 0)
		{
			c->r_length[disp->i_length]--;
			disp->stock[disp->cur] = disp->path;
		}
		else if (disp->stock[disp->cur] == 0 &&
		c->r_length[disp->i_length] <= 0)
			return (i);
		i += print_colored_text(c, str + i, disp);
		if (c->paths[c->result[disp->path]][disp->turns[disp->cur] + 2] == 1)
			disp->turns[disp->cur] = -1;
		else
			disp->turns[disp->cur]++;
		disp->cur++;
	}
	else if (disp->turns[disp->cur] == -1)
		disp->cur++;
	return (i);
}

void	reset_lmatador(t_lem *c, t_display *disp)
{
	disp->i_length -= disp->i_length * (disp->path == c->nb_soluce
		&& disp->cur < disp->max);
	disp->path -= disp->path * (disp->path == c->nb_soluce
		&& disp->cur < disp->max);
}

int		fill_lmatador(t_lem *c, t_display *disp, char *str, int i)
{
	i += ft_sprintf(str + i, "\n");
	while (++disp->id_turn < c->result[0])
	{
		disp->cur = 0;
		disp->path = 0;
		disp->i_length = 0;
		while (++disp->path < c->nb_soluce + 1 && disp->cur < disp->max)
		{
			if (c->result[disp->path] == -1)
			{
				reset_lmatador(c, disp);
				continue ;
			}
			i = fill_lmatador2(c, disp, str, i);
			disp->i_length++;
			reset_lmatador(c, disp);
		}
		disp->max = disp->cur + c->solutions;
		disp->max -= (disp->max - c->ants) * (disp->max > c->ants);
		ft_sprintf(str + i - 1, "\n");
	}
	return (i);
}
