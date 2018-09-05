/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:09:57 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:05:04 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_empty_d(t_flags *flags, t_var *var)
{
	flags->fwidth -= (flags->plus || flags->space);
	flags->fwidth *= (flags->fwidth > 0);
	if (flags->minus)
	{
		if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	else
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
	}
	return (0);
}

int		pf_empty_o(t_flags *flags, t_var *var)
{
	flags->fwidth -= flags->hashtag;
	if (flags->minus)
	{
		if (flags->hashtag)
			addchar('0', var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	else
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (flags->hashtag)
			addchar('0', var);
	}
	return (0);
}

int		pf_empty_u(t_flags *flags, t_var *var)
{
	flags->fwidth = addmchar(' ', var, flags->fwidth);
	return (0);
}

int		pf_empty_x(t_flags *flags, t_var *var, t_uint8 *str)
{
	flags->fwidth -= (str[var->index] == 'p') * 2;
	if (flags->minus)
	{
		if (str[var->index] == 'p')
			addnstr("0x", 2, var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	else
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (str[var->index] == 'p')
			addnstr("0x", 2, var);
	}
	return (0);
}

int		pf_empty_s(t_flags *flags, t_var *var)
{
	char	width;

	width = ' ' + (flags->zero) * 16;
	flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
