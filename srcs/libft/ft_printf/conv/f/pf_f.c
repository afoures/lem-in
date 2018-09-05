/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:30:50 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:30:41 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_fzero(long double d, t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= (flags->hashtag) +
	(flags->space || flags->plus || (d < 0)) + flags->len;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	pf_fcreate(flags, var, d, width);
	var->buf[var->bufindex] = 0;
	return (0);
}

int		pf_nan(t_flags *flags, t_var *var)
{
	char	width;

	flags->fwidth -= 3;
	flags->fwidth *= (flags->fwidth > 0);
	width = ' ' + 16 * flags->zero;
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("nan", 3, var);
	}
	else
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		addnstr("nan", 3, var);
	}
	return (0);
}

int		pf_round(char *str, t_flags *flags, t_var *var)
{
	if (*str >= '5')
	{
		while (*(--str) == '9')
			*str = '0';
		if (*str == '.')
		{
			if (*(str + 2) == 0 && !flags->hashtag)
			{
				*str = 0;
				var->bufindex--;
			}
			*(--str) += 1;
		}
		else
			*str += 1;
	}
	else if (*(--str) == '.' && !flags->hashtag)
		var->bufindex--;
	var->bufindex--;
	return (0);
}

int		pf_f(t_flags *flags, t_var *var, va_list ap)
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
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
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
