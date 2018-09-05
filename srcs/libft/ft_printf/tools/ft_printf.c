/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:14:24 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/05 12:35:18 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_parserror(t_var *var, va_list ap)
{
	if (!var->string)
		write(var->fd, var->buf, var->error);
	else
		pf_memcpy(var->string, var->buf, var->bufindex);
	va_end(ap);
	return (-1);
}

int			ft_printf(const char *str, ...)
{
	static int	(*f[256])() = {NULL};
	va_list		ap;
	t_var		var;
	int			ret;

	va_start(ap, str);
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
	va_end(ap);
	return (var.alwritten + write(1, var.buf, var.bufindex));
}
