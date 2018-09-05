/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:20:54 by afoures           #+#    #+#             */
/*   Updated: 2018/06/01 17:12:28 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_flags(t_lem *c, int ac, char *av[], int *fd)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-u") || !ft_strcmp(av[i], "-usage"))
			display_usage();
		else if (!ft_strcmp(av[i], "-f") || !ft_strcmp(av[i], "-file"))
			*fd = open(av[++i], O_RDONLY);
		else if (!ft_strcmp(av[i], "-d") || !ft_strcmp(av[i], "-debug"))
			c->flags |= 0x3 * !(c->flags & CHEAT) | COLORS;
		else if (!ft_strcmp(av[i], "-c") || !ft_strcmp(av[i], "-colors"))
			c->flags |= COLORS;
		else if (!ft_strcmp(av[i], "-412") || !ft_strcmp(av[i], "-cheat"))
			c->flags = CHEAT | (c->flags & COLORS);
		else
			display_usage();
		i++;
	}
}
