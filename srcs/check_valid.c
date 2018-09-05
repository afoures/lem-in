/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:35:54 by afoures           #+#    #+#             */
/*   Updated: 2018/06/12 17:14:32 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		check_ants(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		check_room(char *line)
{
	int		i;
	int		nb_space;

	i = 0;
	nb_space = 0;
	while (line[i] && line[i] != ' ')
		i++;
	while (line[i])
	{
		if ((line[i] == '-' && line[i - 1] != ' ')
			|| (!ft_isdigit(line[i]) && line[i] != ' '))
			return (0);
		if (line[i] == ' ')
			nb_space++;
		i++;
	}
	if (nb_space > 2)
		return (0);
	return (1);
}

static int		check_pipe(char *line)
{
	int		i;
	int		ok;

	i = 0;
	ok = 0;
	while (line[i])
	{
		if (line[i] == '-')
			ok = 1;
		i++;
	}
	return (ok);
}

int				check_valid(char *line)
{
	int		i;

	i = 0;
	if (line[i] != '#' && !check_ants(line)
			&& !check_room(line) && !check_pipe(line))
		return (-1);
	while (line[i])
		i++;
	return (i);
}
