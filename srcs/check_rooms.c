/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 09:59:28 by afoures           #+#    #+#             */
/*   Updated: 2018/06/05 17:08:02 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_hyphen(t_lem *c)
{
	int		j;

	j = 0;
	while (c->str[c->str_index + j] != ' ')
	{
		if (c->str[c->str_index + j] == '-')
			return (1);
		j++;
	}
	return (0);
}

int			check_valid_coord(t_lem *c)
{
	int		hashtag;
	int		space;

	hashtag = 0;
	space = 0;
	if (c->str[c->str_index] == '#')
		hashtag = 1;
	while (c->str[c->str_index] != ' ' && c->str[c->str_index] != '\n')
		c->str_index++;
	while (c->str[c->str_index] != '\n' && (c->str[c->str_index] == ' '
		|| ft_isdigit(c->str[c->str_index]) || hashtag
		|| (c->str[c->str_index - 1] == ' ' && c->str[c->str_index] == '-')))
		c->str_index++;
	if (c->str[c->str_index] != '\n')
		display_error(NOT_VALID" (coordinates not valid)");
	return (0);
}

void		free_lst(t_lstname *first)
{
	t_lstname	*to_free;
	t_lstname	*tmp;

	to_free = first;
	while (to_free)
	{
		free(to_free->name);
		tmp = to_free;
		to_free = to_free->next;
		free(tmp);
	}
}
