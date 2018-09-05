/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:33:44 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:46:43 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_caparound(char *str, char *base, t_flags *flags, long double d)
{
	if (*str >= base[9 - 1 * (flags->precision != -1)])
	{
		while (*(--str) == base[15])
			flags->len--;
		if (*str != '.')
		{
			if (*str == '9')
				*str += 8;
			else
				*str += 1;
		}
		else
		{
			if (*(--str) == '9')
				*str += 8;
			else
				*str += 1;
			if (!(flags->hashtag && flags->bigl))
				flags->len--;
		}
	}
	else if (flags->len == 2 && (!((intmax_t)d == 0
	&& flags->hashtag && flags->precision != -1)))
		flags->len--;
	return (0);
}

int			pf_capacreate(t_var *var, t_flags *flags, int count, int len_count)
{
	int		start;

	start = var->bufindex - 2 - flags->len;
	addchar('P', var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
	addnstr(ft_itoa(count), len_count, var);
	return (0);
}

static int	initialise(t_flags *flags, t_var *var, long double d)
{
	if (d == 0 && flags->bigl)
		return (pf_capazero(flags, var, d));
	if (!(d == d))
		return (pf_nanc(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinitec(d, flags, var));
	flags->len = 1;
	flags->precision += 15 * (!flags->isp) - 1 * (!flags->bigl);
	flags->capx = 1;
	return (1);
}

int			pf_cap_a(t_flags *flags, t_var *var, va_list ap)
{
	long double	d;
	int			count;
	char		*num;
	int			len_count;

	if (flags->bigl)
		d = va_arg(ap, long double);
	else
		d = va_arg(ap, double);
	if (initialise(flags, var, d) == 0)
		return (0);
	count = pf_toa(&d, flags);
	if ((num = (pf_ftoa_hexa(d, flags))) == NULL)
		return (-1);
	pf_caparound(num + flags->len, "0123456789ABCDEF", flags, d);
	len_count = pf_intlen(count, 10) - (count < 0);
	pf_makecapa(flags, var, d, len_count);
	addnstr(num, flags->len, var);
	pf_capacreate(var, flags, count, len_count);
	if (flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	free(num);
	return (0);
}
