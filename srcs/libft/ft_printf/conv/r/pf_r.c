/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:11:37 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/05 13:59:13 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_nptoh(t_uint8 c, t_flags *flags, t_var *var)
{
	flags->len = 2;
	addnstr("\\0x", 3, var);
	if ((pf_uitoa_hexa(c, flags, var)) == -1)
		return (-1);
	return (1);
}

int			pf_r(t_flags *flags, t_var *var, va_list ap)
{
	char	*str;

	str = va_arg(ap, char*);
	if (!flags->isp)
		flags->precision = ft_strlen(str);
	while (flags->precision-- > 0)
	{
		if (ft_isprint(*str) == 0)
		{
			if ((pf_nptoh((t_uint8)*str, flags, var)) == -1)
				return (-1);
		}
		else
			addchar(*str, var);
		str++;
	}
	return (0);
}
