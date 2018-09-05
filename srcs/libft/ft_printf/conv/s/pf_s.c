/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:44 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/12 15:50:41 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_isnull(t_flags *flags, t_var *var)
{
	char	width;

	width = ' ' + 16 * (flags->zero);
	if (flags->precision > 6 || !flags->isp)
		flags->fwidth -= 6;
	else
		flags->fwidth -= flags->precision;
	flags->fwidth *= (flags->fwidth > 0);
	if (!flags->minus)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		return (addnull(flags, var));
	}
	else
	{
		addnull(flags, var);
		flags->fwidth = addmchar(width, var, flags->fwidth);
		return (0);
	}
}

int		pf_addzero(t_flags *flags, t_var *var)
{
	char	width;

	width = ' ' + 16 * (flags->zero);
	flags->fwidth -= flags->precision * (flags->precision > 0);
	flags->fwidth *= (flags->fwidth > 0);
	flags->fwidth = addmchar(width, var, flags->fwidth);
	return (addnull(flags, var));
}

int		pf_s(t_flags *flags, t_var *var, va_list ap)
{
	char	*tmp;

	if (flags->conv == l)
		return (pf_cap_s(flags, var, ap));
	tmp = va_arg(ap, char*);
	if (flags->precision == 0)
		return (pf_addzero(flags, var));
	if (tmp == NULL)
		return (pf_isnull(flags, var));
	flags->len = ft_strlen(tmp);
	if (flags->precision >= 0 && flags->precision < flags->len)
		flags->len = flags->precision;
	flags->fwidth -= flags->len;
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->minus == 0)
	{
		addmchar(' ' + 16 * (flags->zero), var, flags->fwidth);
		addnstr(tmp, (size_t)flags->len, var);
	}
	else
	{
		addnstr(tmp, (size_t)flags->len, var);
		addmchar(' ' + 16 * (flags->zero), var, flags->fwidth);
	}
	return (0);
}
