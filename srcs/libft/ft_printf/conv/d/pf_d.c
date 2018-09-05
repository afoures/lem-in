/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:50:34 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/13 17:07:48 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_len_d(int (*len_d[7])())
{
	len_d[0] = pf_spe_d;
	len_d[1] = pf_hhd;
	len_d[2] = pf_hd;
	len_d[3] = pf_cap_d;
	len_d[4] = pf_lld;
	len_d[5] = pf_jd;
	len_d[6] = pf_zd;
}

void		create(t_flags *flags, t_var *var, int d)
{
	if (d < 0)
		addchar('-', var);
	else if (flags->plus || flags->space)
		addchar(flags->plus ? '+' : ' ', var);
	d = (d > 0) ? -d : d;
	flags->precision = addmchar('0', var, flags->precision);
	pf_itoa(d, flags, var);
}

char		dinitialise(t_flags *flags, int d)
{
	int		test;
	int		flag;
	int		apo;

	flags->len = pf_intlen(d, 10);
	test = (d < 0);
	apo = (flags->tsep != 0) * ((flags->len / 3) - (flags->len % 3 == 0));
	flag = ((flags->space || flags->plus) && !test);
	flags->precision -= (flags->len - test) + apo;
	flags->precision *= flags->precision > 0;
	flags->fwidth -= flags->len + flags->precision + flag + apo;
	flags->fwidth *= (flags->fwidth > 0);
	flags->len -= 1 * (d < 0);
	return (' ');
}

int			pf_d(t_flags *flags, t_var *var, va_list ap)
{
	static int	(*len_d[7])();

	if (len_d[0] == NULL)
		init_len_d(len_d);
	return (len_d[flags->conv](flags, var, ap));
}

int			pf_spe_d(t_flags *flags, t_var *var, va_list ap)
{
	char		width;
	int			d;

	d = va_arg(ap, int);
	if (d == 0 && flags->precision == 0)
		return (pf_empty_d(flags, var));
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
