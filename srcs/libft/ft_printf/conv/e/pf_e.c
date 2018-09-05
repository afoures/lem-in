/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:44:53 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:40:20 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_tosc(long double *d)
{
	int		count;

	count = 0;
	if (*d == 0)
		return (0);
	while (*d < 1 && *d > -1)
	{
		*d = *d * 10;
		count--;
	}
	while (*d < -10 || *d > 10)
	{
		*d /= 10;
		count++;
	}
	return (count);
}

static int	pf_create(t_flags *flags, t_var *var, long double d, int count)
{
	pf_ftoa(d, flags, var);
	if (flags->precision == 0 && flags->hashtag)
		var->bufindex--;
	pf_round(&var->buf[var->bufindex - 1], flags, var);
	addchar('e', var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
	if (count < 10)
		addchar('0', var);
	addnstr(ft_itoa(count), 1, var);
	return (0);
}

static int	initialise(t_flags *flags, t_var *var, long double d)
{
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
	flags->precision += 7 * (!flags->isp);
	flags->fwidth -= flags->precision + 5
	+ (flags->precision != 0 || flags->hashtag)
	+ (d < 0 || flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	return (0);
}

int			pf_e(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;
	int			count;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	count = pf_tosc(&d);
	initialise(flags, var, d);
	return (pf_spe_e(flags, var, d, count));
}

int			pf_spe_e(t_flags *flags, t_var *var, long double d, int count)
{
	if (!flags->minus)
	{
		if (flags->zero)
		{
			pf_addminp(flags, var, d);
			flags->fwidth = addmchar('0', var, flags->fwidth);
		}
		else
		{
			flags->fwidth = addmchar(' ', var, flags->fwidth);
			pf_addminp(flags, var, d);
		}
		pf_create(flags, var, d, count);
	}
	else
	{
		pf_addminp(flags, var, d);
		pf_create(flags, var, d, count);
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	}
	return (0);
}
