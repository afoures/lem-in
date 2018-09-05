/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:09:27 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_wildcard(t_flags *flags, t_var *var, va_list ap, t_uint8 *str)
{
	int		wdc;

	wdc = va_arg(ap, int);
	if (str[var->index - 1] == '.')
	{
		if (wdc < 0)
		{
			return (1);
		}
		flags->precision = wdc;
		flags->isp = 1;
	}
	else
	{
		if (wdc < 0)
		{
			flags->zero = 0;
			flags->minus = 1;
			wdc = -wdc;
		}
		flags->fwidth = wdc;
		flags->isw = 1;
	}
	return (1);
}
