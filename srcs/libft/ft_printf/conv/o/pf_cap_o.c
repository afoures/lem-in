/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:12 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create(t_flags *flags, t_var *var, unsigned long int d)
{
	if (flags->hashtag)
		addchar('0', var);
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_base(d, 8, flags, var);
}

static char	initialise(t_flags *flags, unsigned long int d)
{
	int		apo;

	flags->len = pf_uintlen(d, 8);
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->hashtag *= (d != 0 && !flags->precision);
	flags->fwidth -= flags->len + flags->precision + flags->hashtag;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int			pf_cap_o(t_flags *flags, t_var *var, va_list ap)
{
	char				width;
	unsigned long int	d;

	d = va_arg(ap, unsigned long int);
	if (d == 0 && flags->precision == 0 && !flags->hashtag)
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
