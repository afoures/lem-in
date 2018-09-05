/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:44:40 by rbalbous          #+#    #+#             */
/*   Updated: 2018/06/01 16:51:47 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, char *av[])
{
	int			fd;
	t_lem		c;

	fd = 0;
	c.flags = 0;
	if (ac > 1)
		get_flags(&c, ac, av, &fd);
	parsing(fd, &c);
	check_links(&c);
	solver(&c);
	display(&c, 0);
	if (ac > 1)
		close(fd);
	return (0);
}
