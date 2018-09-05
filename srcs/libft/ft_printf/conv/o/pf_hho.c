/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hho.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 14:37:59 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create(t_flags *flags, t_var *var, t_uint8 d)
{
	if (flags->hashtag)
		addchar('0', var);
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_base(d, 8, flags, var);
}

static char	initialise(t_flags *flags, t_uint8 d)
{
	flags->len = pf_uintlen(d, 8);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->hashtag *= (d != 0 && !flags->precision);
	flags->fwidth -= flags->len + flags->precision + flags->hashtag;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int			pf_hho(t_flags *flags, t_var *var, va_list ap)
{
	char	width;
	t_uint8	d;

	d = (t_uint8)va_arg(ap, int);
	if (d == 0 && flags->precision == 0)
		return (pf_empty_o(flags, var));
	width = initialise(flags, d);
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
