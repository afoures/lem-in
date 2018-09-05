/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colored_text.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 13:49:12 by afoures           #+#    #+#             */
/*   Updated: 2018/05/07 16:20:33 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_colored_text(t_lem *c, char *str, t_display *disp)
{
	t_color	c3;

	if (c->flags & COLORS)
	{
		c3.color = get_color((t_color)0XFF0000, (t_color)0xFFFF00,
				(double)disp->i_length / (double)c->solutions);
		return (ft_sprintf(str, "\033[38;2;%d;%d;%d2mL%d-%s\033[m ", c3.rgb[2],
				c3.rgb[1], c3.rgb[0], disp->cur + 1, c->rooms[c->paths[c->result
				[disp->path]][disp->turns[disp->cur] + 2]].name));
	}
	return (ft_sprintf(str, "L%d-%s ", disp->cur + 1
, c->rooms[c->paths[c->result[disp->path]][disp->turns[disp->cur] + 2]].name));
}

int		print_colored_text2bis(t_lem *c, char *str, t_display *disp)
{
	int		i;
	t_color	c3;

	i = 0;
	c3 = (t_color)0XFF0000;
	if (disp->cur == 0)
	{
		return (ft_sprintf(str, "\033[38;2;%d;%d;%d2mL%d-%s\033[m\n",
					c3.rgb[2], c3.rgb[1], c3.rgb[0], disp->cur + 1, "412"));
	}
	i = ft_sprintf(str, "\033[38;2;%d;%d;%d2mL%d-%s\033[m ", c3.rgb[2],
			c3.rgb[1], c3.rgb[0], disp->cur, c->rooms[1].name);
	if (disp->cur + 1 > disp->max)
		return (i);
	return (ft_sprintf(str + i, "\033[38;2;%d;%d;%d2mL%d-%s\033[m\n",
				c3.rgb[2], c3.rgb[1], c3.rgb[0], disp->cur + 1, "412") + i);
}

int		print_colored_text2(t_lem *c, char *str, t_display *disp)
{
	int		i;
	t_color	c3;

	i = 0;
	c3 = (t_color)0XFF0000;
	if (!(c->flags & CHEAT))
	{
		if (c->flags & COLORS)
		{
			return (ft_sprintf(str, "\033[38;2;%d;%d;%d2mL%d-%s\033[m ",
					c3.rgb[2], c3.rgb[1], c3.rgb[0], disp->cur + 1,
					c->rooms[1].name));
		}
		return (ft_sprintf(str, "L%d-%s ", disp->cur + 1, c->rooms[1].name));
	}
	if (c->flags & COLORS)
		return (print_colored_text2bis(c, str, disp));
	if (disp->cur == 0)
		return (ft_sprintf(str, "L%d-%s\n", disp->cur + 1, "412"));
	i = ft_sprintf(str, "L%d-%s ", disp->cur, c->rooms[1].name);
	if (disp->cur + 1 > disp->max)
		return (i);
	return (ft_sprintf(str + i, "L%d-%s\n", disp->cur + 1, "412") + i);
}
