/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:17:57 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 15:24:29 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_initflags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->hashtag = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->isp = 0;
	flags->isw = 0;
	flags->precision = -1;
	flags->fwidth = 0;
	flags->capx = 0;
	flags->cast = ' ';
	flags->tsep = 0;
	flags->dpt = 0;
	flags->len = 0;
	flags->bigl = 0;
	flags->conv = none;
	return (0);
}

int		parse(t_uint8 *str, t_var *var, va_list ap, int (*f[256])())
{
	t_flags flags;
	int		ret;

	pf_initflags(&flags);
	var->index++;
	while (str[var->index])
	{
		if ((ret = f[(int)str[var->index]](&flags, var, ap, str)) <= 0)
			return (ret);
		var->index++;
	}
	va_end(flags.begin);
	return (-2);
}
