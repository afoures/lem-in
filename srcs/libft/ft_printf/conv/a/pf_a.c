/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:07:23 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:44:07 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_around(char *str, char *base, t_flags *flags, long double d)
{
	if (*str >= base[9 - 1 * (flags->precision != -1)])
	{
		while (*(--str) == base[15])
			flags->len--;
		if (*str != '.')
		{
			if (*str == '9')
				*str += 40;
			else
				*str += 1;
		}
		else
		{
			if (*(--str) == '9')
				*str += 40;
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

int			pf_toa(long double *d, t_flags *flags)
{
	int		count;
	int		sign;

	count = 0;
	sign = 1;
	if (flags->bigl)
		return (pf_tola(d));
	if ((intmax_t)(*d) == 0 && *d != 0)
	{
		while ((intmax_t)(*d) == 0)
		{
			*d = *d * 2;
			count++;
			sign = -1;
		}
	}
	while ((1 < (intmax_t)(*d) || -1 > (intmax_t)(*d)) && *d != 0)
	{
		*d /= 2;
		count++;
	}
	return (count * sign);
}

int			pf_acreate(t_var *var, t_flags *flags, int count, int len_count)
{
	int		start;

	start = var->bufindex - 2 - flags->len;
	addchar('p', var);
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
		return (pf_azero(flags, var, d));
	if (!(d == d))
		return (pf_nan(flags, var));
	if (d == INFINITY || d == -INFINITY)
		return (pf_infinite(d, flags, var));
	flags->len = 1;
	flags->precision += 15 * (!flags->isp) - 1 * (!flags->bigl);
	return (1);
}

int			pf_a(t_flags *flags, t_var *var, va_list ap)
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
	pf_around(num + flags->len, "0123456789abcdef", flags, d);
	len_count = pf_intlen(count, 10) - (count < 0);
	pf_makea(flags, var, d, len_count);
	addnstr(num, flags->len, var);
	pf_acreate(var, flags, count, len_count);
	if (flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	free(num);
	return (0);
}
