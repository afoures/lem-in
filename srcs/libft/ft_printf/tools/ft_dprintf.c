/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:54:48 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/05 12:36:09 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf(int fd, const char *str, ...)
{
	static int	(*f[256])() = {NULL};
	va_list		ap;
	t_var		var;

	va_start(ap, str);
	if (initialise_var(&var, ap, f, (char*)str))
		return (-1);
	var.fd = fd;
	while (str[++var.index])
	{
		if (str[var.index] == '%' && str[var.index + 1])
		{
			if ((var.ret = parse((t_uint8*)str, &var, ap, f)) < 0)
			{
				if (var.ret == -2)
					break ;
				return (pf_parserror(&var, ap));
			}
			var.error = var.bufindex;
		}
		else if (str[var.index] != '%')
			addchar(str[var.index], &var);
	}
	va_end(ap);
	return (write(fd, var.buf, var.bufindex));
}
