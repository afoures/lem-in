/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:28 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_len_o(int (*len_o[7])())
{
	len_o[0] = pf_spe_o;
	len_o[1] = pf_hho;
	len_o[2] = pf_ho;
	len_o[3] = pf_cap_o;
	len_o[4] = pf_llo;
	len_o[5] = pf_jo;
	len_o[6] = pf_zo;
}

static void	create(t_flags *flags, t_var *var, t_uint32 d)
{
	if (flags->hashtag)
		addchar('0', var);
	flags->precision = addmchar('0', var, flags->precision);
	pf_uitoa_base(d, 8, flags, var);
}

static char	initialise(t_flags *flags, t_uint32 d)
{
	flags->len = pf_uintlen(d, 8);
	flags->precision -= flags->len;
	flags->precision *= flags->precision > 0;
	flags->hashtag *= (d != 0 && flags->precision <= 0);
	flags->fwidth -= flags->len + flags->precision + flags->hashtag;
	flags->fwidth *= (flags->fwidth > 0);
	return (' ');
}

int			pf_o(t_flags *flags, t_var *var, va_list ap)
{
	static int	(*len_o[7])();

	if (len_o[0] == NULL)
		init_len_o(len_o);
	return (len_o[flags->conv](flags, var, ap));
}

int			pf_spe_o(t_flags *flags, t_var *var, va_list ap)
{
	char		width;
	t_uint32	d;

	d = va_arg(ap, t_uint32);
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
