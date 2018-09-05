/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:36:58 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create(t_flags *flags, t_var *var, t_uint16 d)
{
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_base(d, 10, flags, var);
}

static char	dinitialise(t_flags *flags, t_uint16 d)
{
	int		apo;

	flags->len = pf_uintlen(d, 10);
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->precision -= flags->len + apo;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + apo;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int			pf_hu(t_flags *flags, t_var *var, va_list ap)
{
	char			width;
	t_uint16		d;

	d = (t_uint16)va_arg(ap, t_uint32);
	if (d == 0 && flags->precision == 0)
		return (pf_empty_u(flags, var));
	width = dinitialise(flags, d);
	if (!flags->minus)
	{
		if (flags->zero && !flags->isp)
		{
			flags->precision = flags->fwidth;
			flags->fwidth = 0;
		}
		flags->fwidth = addmchar(width, var, flags->fwidth);
		create(flags, var, d);
	}
	else
	{
		create(flags, var, d);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}
