/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:55:25 by afoures           #+#    #+#             */
/*   Updated: 2018/06/01 16:51:21 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_usage(void)
{
	ft_dprintf(2, "%s", USAGE1);
	ft_dprintf(2, "%s", USAGE2);
	ft_dprintf(2, "%s", USAGE3);
	ft_dprintf(2, "%s", USAGE4);
	ft_dprintf(2, "%s\n", USAGE5);
	exit(0);
}

void	display_error(char *error)
{
	ft_dprintf(2, "%s\n", error);
	exit(-1);
}
