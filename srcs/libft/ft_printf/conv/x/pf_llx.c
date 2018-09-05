/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_llx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:11:07 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/15 17:44:26 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	create(t_flags *flags, t_var *var, long long int d)
{
	char	x;

	x = 'x' - flags->capx * 32;
	if (flags->hashtag)
	{
		addchar('0', var);
		addchar(x, var);
	}
	flags->precision = addmchar('0', var, flags->precision);
	if ((pf_uitoa_hexa(d, flags, var)) == -1)
		return (-1);
	return (0);
}

static char	dinitialise(t_flags *flags, long long int d)
{
	flags->len = pf_uintlen(d, 16);
	flags->hashtag *= (d != 0);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flags->hashtag * 2;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int			pf_llx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str)
{
	char			width;
	long long int	d;

	d = va_arg(ap, long long int);
	if (d == 0 && flags->precision == 0)
		return (pf_empty_x(flags, var, str));
	width = dinitialise(flags, d);
	if (!flags->minus)
	{
		if (flags->zero && !flags->isp)
		{
			flags->precision = flags->fwidth;
			flags->fwidth = 0;
		}
		flags->fwidth = addmchar(width, var, flags->fwidth);
		if ((create(flags, var, d)) == -1)
			return (-1);
	}
	else
	{
		if ((create(flags, var, d)) == -1)
			return (-1);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}
