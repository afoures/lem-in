/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_lx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 21:48:24 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/15 17:58:58 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		xcreate(t_flags *flags, t_var *var, t_uint64 d, t_uint8 *str)
{
	char	x;

	x = 'x' - flags->capx * 32;
	if (flags->hashtag || str[var->index] == 'p')
	{
		addchar('0', var);
		addchar(x, var);
	}
	flags->precision = addmchar('0', var, flags->precision);
	if ((pf_uitoa_hexa(d, flags, var)) == -1)
		return (-1);
	return (1);
}

char	xinitialise(t_var *var, t_flags *flags, t_uint64 d, t_uint8 *str)
{
	flags->len = pf_uintlen(d, 16);
	flags->hashtag = (str[var->index] == 'p') || flags->hashtag * (d != 0);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flags->hashtag * 2;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int		pf_lx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str)
{
	char		width;
	t_uint64	d;

	d = va_arg(ap, t_uint64);
	if (d == 0 && flags->precision == 0)
		return (pf_empty_x(flags, var, str));
	width = xinitialise(var, flags, d, str);
	if (!flags->minus)
	{
		if (flags->zero && !flags->isp)
		{
			flags->precision = flags->fwidth;
			flags->fwidth = 0;
		}
		flags->fwidth = addmchar(width, var, flags->fwidth);
		if ((xcreate(flags, var, d, str)) == -1)
			return (-1);
	}
	else
	{
		if ((xcreate(flags, var, d, str)) == -1)
			return (-1);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}
