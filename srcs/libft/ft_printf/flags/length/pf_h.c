/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_h.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:24:49 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/13 19:12:11 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_h(t_flags *flags)
{
	if (flags->conv > h)
		return (1);
	if (flags->conv == h)
	{
		flags->conv = hh;
		return ('H');
	}
	flags->conv = h;
	return ('h');
}
