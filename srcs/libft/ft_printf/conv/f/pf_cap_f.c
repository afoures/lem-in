/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 17:22:00 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:34:27 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_nanc(t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= 3;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("NAN", 3, var);
	}
	else
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("NAN", 3, var);
	}
	return (0);
}

int		pf_infinitec(long double d, t_flags *flags, t_var *var)
{
	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= 3 + (flags->space || flags->plus || d < 0);
	flags->fwidth *= (flags->fwidth > 0);
	if (!flags->minus)
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("INF", 3, var);
	}
	else
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("INF", 3, var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	return (0);
}

int		pf_cap_f(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;
	int			apo;
	char		width;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	width = ' ' + 16 * flags->zero;
	if (!(d == d))
		return (pf_nanc(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinitec(d, flags, var));
	flags->len = pf_intlen((intmax_t)d, 10) - (d < 0);
	if (flags->precision == 0)
		return (pf_fzero(d, flags, var));
	flags->precision += 7 * (!flags->isp);
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->fwidth -= flags->precision + flags->len
	+ (flags->space || flags->plus || d < 0) + apo + 1;
	flags->fwidth *= (flags->fwidth > 0);
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
	return (0);
}
