/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_la.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:33:44 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:04:28 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_makecapa(t_flags *flags, t_var *var, long double d, int lc)
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
		addnstr("0X", 2, var);
	}
	if (!flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	if (!flags->zero)
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus * 11 + ' ', var);
		addnstr("0X", 2, var);
	}
	return (0);
}

int			pf_capazero(t_flags *flags, t_var *var, long double d)
{
	char	width;

	flags->fwidth -= 6 + (flags->space || flags->plus || d < 0)
	+ (flags->precision > 0 || flags->hashtag) + flags->precision * flags->isp;
	pf_makecapa(flags, var, d, 0);
	width = ' ' + 16 * flags->zero;
	addchar('0', var);
	if (flags->precision > 0 || flags->hashtag)
		addchar('.', var);
	while (flags->precision-- > 0)
		addchar('0', var);
	addnstr("P+0", 3, var);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
