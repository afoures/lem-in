/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preci.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:36:39 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:57 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_preci(t_flags *flags, t_var *var, va_list ap, t_uint8 *str)
{
	(void)ap;
	var->index++;
	if (str[var->index] == '*')
		return (pf_wildcard(flags, var, ap, str));
	flags->isp = 1;
	flags->precision = 0;
	while (str[var->index] && ft_isdigit(str[var->index]) == 1)
	{
		flags->precision = flags->precision * 10 + (str[var->index] - 48);
		var->index++;
	}
	var->index--;
	return (1);
}
