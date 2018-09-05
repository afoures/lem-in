/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:00 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/12 15:55:16 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len_one(wint_t c, t_var *var)
{
	addchar((const char)c, var);
	return (1);
}

int		len_two(wint_t c, t_var *var)
{
	t_uint32	byte;

	byte = (((c & 0x3F) << 8) | (c >> 6)) | 0x80C0;
	addnstr(&byte, 2, var);
	return (1);
}

int		len_three(wint_t c, t_var *var)
{
	t_uint32	byte;

	byte = ((((c & 0x3F) << 16) | (((c >> 6) & 0x3F) << 8))
	| (c >> 12)) | 0x8080E0;
	addnstr(&byte, 3, var);
	return (1);
}

int		len_four(wint_t c, t_var *var)
{
	t_uint32	byte;

	byte = (((c & 0x3F) << 24) | (((c >> 6) & 0x3F) << 16)
	| (((c >> 12) & 0x3F) << 8) | (c >> 18)) | 0x808080F0;
	addnstr(&byte, 4, var);
	return (1);
}

int		pf_cap_c(t_flags *flags, t_var *var, va_list ap)
{
	wint_t		c;
	static int	(*u[4])() = {len_one, len_two, len_three, len_four};

	c = va_arg(ap, wint_t);
	if (c > 0x10ffff || (0xd800 <= c && 0xdfff >= c) || c < 0
	|| (MB_CUR_MAX == 1 && c > 255))
		return (-1);
	flags->len = 1 * (!(c >> (7 + (MB_CUR_MAX == 1))));
	flags->len += 2 * (!(c >> 11) && !flags->len);
	flags->len += 3 * (!(c >> 16) && !flags->len);
	flags->len += 4 * (!(c >> 21) && !flags->len);
	flags->fwidth -= flags->len;
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->minus == 0)
	{
		flags->fwidth = addmchar(' ' + 16 * (flags->zero), var, flags->fwidth);
		u[flags->len - 1](c, var);
	}
	else
	{
		u[flags->len - 1](c, var);
		flags->fwidth = addmchar(' ' + 16 * (flags->zero), var, flags->fwidth);
	}
	return (0);
}
