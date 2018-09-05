/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:30:50 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:35:55 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_infinite(long double d, t_flags *flags, t_var *var)
{
	flags->fwidth -= 3 + (flags->space || flags->plus || d < 0);
	flags->fwidth *= (flags->fwidth > 0);
	if (!flags->minus)
	{
		flags->fwidth = addmchar(' ', var, flags->fwidth);
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("inf", 3, var);
	}
	else
	{
		if (d < 0)
			addchar('-', var);
		else if (flags->plus || flags->space)
			addchar(flags->plus ? '+' : ' ', var);
		addnstr("inf", 3, var);
		flags->fwidth = addmchar(' ', var, flags->fwidth);
	}
	return (0);
}

void	pf_addminp(t_flags *flags, t_var *var, long double d)
{
	if (d < 0)
		addchar('-', var);
	else if ((flags->plus || flags->space))
		addchar(flags->plus ? '+' : ' ', var);
}

int		pf_fcreate(t_flags *flags, t_var *var, long double d, char width)
{
	if (!flags->minus)
	{
		if (flags->zero)
		{
			pf_addminp(flags, var, d);
			flags->fwidth = addmchar(width, var, flags->fwidth);
		}
		else
		{
			flags->fwidth = addmchar(width, var, flags->fwidth);
			pf_addminp(flags, var, d);
		}
	}
	if (flags->minus)
		pf_addminp(flags, var, d);
	pf_ftoa(d, flags, var);
	if (flags->precision == 0 && flags->hashtag)
		var->bufindex--;
	pf_round(&var->buf[var->bufindex - 1], flags, var);
	if (flags->minus)
		flags->fwidth = addmchar(width, var, flags->fwidth);
	return (0);
}
