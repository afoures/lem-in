/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_g.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 20:42:14 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/22 15:02:19 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_gzer(t_flags *flags, t_var *var, long double d)
{
	long double	tmp;
	int			count;

	tmp = d;
	count = 0;
	while ((intmax_t)tmp == 0 && d != 0)
	{
		tmp *= 10;
		count--;
	}
	if (count > flags->precision || count < -4)
		return (pf_ge(flags, var, tmp, count));
	else
		return (pf_gf(flags, var, d));
	return (0);
}

int		pf_gpos(t_flags *flags, t_var *var, long double d)
{
	int			count;
	int			leng;

	leng = pf_intlen((intmax_t)d, 10) - (d < 0);
	if (leng > 6 || (flags->precision + 1 < leng))
	{
		count = pf_tosc(&d);
		pf_ge(flags, var, d, count);
	}
	else
		pf_gf(flags, var, d);
	return (1);
}

int		pf_cap_g(t_flags *flags, t_var *var, va_list ap)
{
	flags->capx = 1;
	return (pf_g(flags, var, ap));
}

int		pf_g(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->precision += (!flags->isp) * 7 - 1;
	flags->precision *= (flags->precision > 0);
	if ((intmax_t)d == 0)
		pf_gzer(flags, var, d);
	else
		pf_gpos(flags, var, d);
	return (0);
}
