/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_zx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:16:58 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/15 17:49:06 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	create(t_flags *flags, t_var *var, size_t d)
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
	return (1);
}

static char	dinitialise(t_flags *flags, size_t d)
{
	flags->len = pf_uintlen(d, 16);
	flags->hashtag *= (d != 0);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flags->hashtag * 2;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int			pf_zx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str)
{
	char	width;
	size_t	d;

	d = va_arg(ap, size_t);
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
