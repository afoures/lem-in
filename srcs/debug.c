/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 17:12:11 by afoures           #+#    #+#             */
/*   Updated: 2018/05/05 22:12:38 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_all_rooms(t_lem *c, t_color c1, t_color c2)
{
	int		i;
	int		j;
	int		n;
	t_color	c3;

	i = -1;
	n = 0;
	c3.color = get_color(c1, c2, (double)(3. / 5.));
	while (++i < c->nb_rooms)
	{
		j = -1;
		ft_printf("\033[38;2;0;255;02m[%s]%n", c->rooms[i].name, &n);
		ft_printf("%*c \033[m", c->max_len + 19 - n, ':');
		while (++j < c->rooms[i].nb_links)
			ft_printf("\033[38;2;%d;%d;%d2m[%s]", c3.rgb[2], c3.rgb[1],
				c3.rgb[0], c->rooms[c->rooms[i].links[j]].name);
		ft_printf("\033[m\n");
	}
}

void	display_all_paths(t_lem *c, t_color c1, t_color c2)
{
	int		i;
	int		j;
	t_color	c3;

	i = -1;
	while (++i < c->nb_paths)
	{
		ft_printf("\033[%dm[%d] : ", 33, c->paths[i][0]);
		j = 0;
		ft_printf("\033[38;2;%d;%d;%d2m{%s}", c1.rgb[2], c1.rgb[1],
			c1.rgb[0], c->rooms[c->paths[i][2]].name);
		while (++j < c->paths[i][1])
		{
			c3.color = get_color(c1, c2,
				(double)((double)j / (double)c->paths[i][1]));
			ft_printf("\033[38;2;%d;%d;%d2m-{%s}", c3.rgb[2], c3.rgb[1],
				c3.rgb[0], c->rooms[c->paths[i][j + 2]].name);
		}
		ft_printf("\033[m\n");
	}
}

void	display_all_solutions(t_lem *c, t_color c1, t_color c2, int k)
{
	int		i;
	int		j;
	t_color	c3;

	i = 0;
	while (++i < c->nb_soluce + 1)
	{
		if (c->result[i] == -1)
			continue ;
		c3.color = get_color((t_color)0XFF0000, (t_color)0xFFFF00,
			(double)k / (double)c->solutions);
		ft_printf("\033[38;2;%d;%d;%d2m[%d] (%d ants): ", c3.rgb[2], c3.rgb[1],
				c3.rgb[0], c->paths[c->result[i]][0], c->r_length[k++]);
		ft_printf("\033[38;2;0;181;2272m{%s}",
			c->rooms[c->paths[c->result[i]][2]].name);
		j = 0;
		while (++j < c->paths[c->result[i]][1])
		{
			c3.color = get_color(c1, c2,
				(double)j / (double)c->paths[c->result[i]][1]);
			ft_printf("\033[38;2;%d;%d;%d2m-{%s}", c3.rgb[2], c3.rgb[1],
				c3.rgb[0], c->rooms[c->paths[c->result[i]][j + 2]].name);
		}
		ft_printf("\033[m\n");
	}
}

void	display_debug(t_lem *c)
{
	ft_printf("\n\033[35;1m[DEBUG MODE]\033[m\n\n");
	ft_printf("\033[38;2;0;255;02m[ALL ROOMS]\n");
	display_all_rooms(c, (t_color)0x00b5e3, (t_color)0xad00e3);
	ft_printf("\n\033[33m[ALL PATHS]\033[m\n");
	display_all_paths(c, (t_color)0x00b5e3, (t_color)0xad00e3);
	ft_printf("\n\033[38;2;255;0;02m[SOLUTIONS]\033[m\n");
	display_all_solutions(c, (t_color)0x00b5e3, (t_color)0xad00e3, 0);
}
