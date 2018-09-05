/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoures <afoures@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 16:03:44 by afoures           #+#    #+#             */
/*   Updated: 2018/05/07 13:58:10 by afoures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <math.h>

int		get_color(t_color c1, t_color c2, double k)
{
	int		i;
	t_color	c;

	i = -1;
	while (++i < 4)
		c.rgb[i] = c1.rgb[i] + (c2.rgb[i] - c1.rgb[i]) * k;
	return (c.color);
}
