/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:34:08 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 18:13:38 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_dol_l(t_flags *flags, t_var *var, t_uint8 *str)
{
	if (flags->conv > l)
		return (1);
	if (flags->conv == l && str[var->index - 1] == 'l')
	{
		flags->conv = ll;
		return ('L');
	}
	flags->conv = l;
	return ('l');
}

int		pf_dol_h(t_flags *flags)
{
	if (flags->conv > h)
		return (1);
	if (flags->conv == h)
	{
		flags->conv = hh;
		return ('H');
	}
	flags->conv = h;
	return ('h');
}

int		pf_dol_s(void)
{
	return ('s');
}

int		pf_none(t_flags *flags, t_var *var, t_uint8 *str)
{
	(void)flags;
	if (str[var->index] == '%')
		return (-1);
	return (0);
}

int		pf_dol_f(t_flags *flags, t_var *var, t_uint8 *str)
{
	(void)flags;
	if (str[var->index - 1] == 'L')
		return ('F');
	return ('f');
}
