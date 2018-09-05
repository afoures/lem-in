/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:10:52 by afoures           #+#    #+#             */
/*   Updated: 2018/06/12 16:59:42 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		go_to_ants(t_lem *c)
{
	int		i;

	i = 0;
	while (c->str[c->str_index + i] && !ft_isdigit(c->str[c->str_index + i]))
	{
		while (c->str[c->str_index + i] && ft_ispace(c->str[c->str_index + i]))
			i++;
		if (ft_isdigit(c->str[c->str_index + i]))
			break ;
		while (c->str[c->str_index + i] && c->str[c->str_index + i] != '\n')
			i++;
		i++;
		c->str_index += i;
		i = 0;
	}
	while (c->str[c->str_index + i] && c->str[c->str_index + i] != '\n')
	{
		if (!ft_isdigit(c->str[c->str_index + i])
			&& !ft_ispace(c->str[c->str_index + i]))
			display_error(NO_ANTS);
		i++;
	}
}

int				parsing(int fd, t_lem *c)
{
	t_lstname	*lst;
	t_file		file;

	c->str = NULL;
	c->str_index = 0;
	file.fd = 0;
	file.size = GNL_SIZE;
	file.fd = fd;
	file.cursor = 0;
	if (!(file.data = (char *)ft_memalloc(sizeof(char) * file.size)))
		display_error(MALLOC);
	c->str_len = read_file(&file);
	c->str = file.data;
	c->nb_soluce = 0;
	if (!c->str)
		display_error(EMPTY);
	go_to_ants(c);
	if ((c->ants = ft_atoi(c->str + c->str_index)) <= 0)
		display_error(NO_ANTS);
	c->antlen = ft_intlen(c->ants);
	lst = NULL;
	c->rooms = NULL;
	get_rooms(lst, c);
	get_pipes(c);
	return (0);
}
