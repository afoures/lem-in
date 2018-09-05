/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_la.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:07:23 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:04:48 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_makea(t_flags *flags, t_var *var, long double d, int lc)
{
	flags->fwidth -= (flags->len + lc + (flags->space || flags->plus || d < 0) +
	4 + (flags->precision == -1 && flags->hashtag)) * !(flags->bigl && d == 0);
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->precision == -1 && flags->hashtag)
		flags->len++;
	if (flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addnstr("0x", 2, var);
	}
	if (!flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	if (!flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addnstr("0x", 2, var);
	}
	return (0);
}

int			pf_azero(t_flags *flags, t_var *var, long double d)
{
	char	width;

	flags->fwidth -= 6 + (flags->space || flags->plus || d < 0)
	+ (flags->precision > 0 || flags->hashtag) + flags->precision * flags->isp;
	pf_makea(flags, var, d, 0);
	width = ' ' + 16 * flags->zero;
	addchar('0', var);
	if (flags->precision > 0 || flags->hashtag)
		addchar('.', var);
	while (flags->precision-- > 0)
		addchar('0', var);
	addnstr("p+0", 3, var);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}

int			pf_tola(long double *d)
{
	int		count;

	count = -2 + (*d < 1 && *d > -1) * -2;
	*d *= 4 + (*d < 1 && *d > -1) * 12;
	while (16 < (*d) || -16 > (*d))
	{
		*d /= 2;
		count++;
	}
	while (8 > (*d) && -8 < (*d))
	{
		*d *= 2;
		count--;
	}
	return (count);
}
