/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:20:33 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 18:27:38 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vprintf(const char *str, va_list ap)
{
	static int	(*f[256])() = {NULL};
	t_var		var;
	int			ret;

	if (initialise_var(&var, ap, f, (char*)str))
		return (-1);
	while (str[++var.index])
	{
		if (str[var.index] == '%' && str[var.index + 1])
		{
			if ((ret = parse((t_uint8*)str, &var, ap, f)) < 0)
			{
				if (ret == -2)
					break ;
				return (pf_parserror(&var, ap));
			}
			var.error = var.bufindex;
		}
		else if (str[var.index] != '%')
			addchar(str[var.index], &var);
	}
	return (write(1, var.buf, var.bufindex));
}
