/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 11:09:55 by afoures           #+#    #+#             */
/*   Updated: 2018/06/05 17:11:33 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display(t_lem *c, int throll)
{
	char		*str;
	int			len;
	t_display	disp;

	str = NULL;
	len = 0;
	disp = (t_display){0, 0, 0, 0, 0, 0, 0, -1};
	disp.max = (c->solutions > c->ants) ? c->ants : c->solutions;
	if (!(disp.stock = (int *)ft_memalloc(sizeof(int*) * (c->ants + 1)))
	| !(disp.turns = (int *)ft_memalloc(sizeof(int) * (c->ants + 1))))
		display_error(MALLOC);
	str = create_lmatador(c);
	write(1, c->str, c->str_index);
	if (c->str[c->str_index - 1] != '\n')
		write(1, "\n", 1);
	if (c->flags & DEBUG)
		display_debug(c);
	len = (!throll && !(c->flags & CHEAT)) ? fill_lmatador(c, &disp, str, 0) :
			fill_lmatador3(c, &disp, str, 0);
	write(1, str, len);
	free(str);
	free(disp.stock);
	free(disp.turns);
	if (throll || c->flags & CHEAT)
		exit(0);
}
