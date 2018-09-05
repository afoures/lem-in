/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:26:17 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/22 14:43:08 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_aground(char *str, t_flags *flags, long double d)
{
	(void)d;
	if (*str >= '5')
	{
		while (*(--str) == '9')
		{
			*str = '0';
			flags->len -= (!flags->hashtag);
		}
		if (*str != '.')
		{
			*str += 1;
		}
		else
		{
			*(--str) += 1;
		}
	}
	while (*(--str) == '0' && !flags->hashtag)
		flags->len--;
	if (flags->len == 2 && !flags->hashtag)
		flags->len--;
	return (0);
}

static int	pf_create(t_flags *flags, t_var *var, int count)
{
	addchar('e' - flags->capx * 32, var);
	if (count < 0)
	{
		addchar('-', var);
		count *= -1;
	}
	else
		addchar('+', var);
	if (count < 10)
		addchar('0', var);
	addnstr(ft_itoa(count), 1, var);
	return (0);
}

void		pf_addge(t_flags *flags, t_var *var, long double d)
{
	if (!flags->minus)
	{
		if (flags->zero)
		{
			pf_addminp(flags, var, d);
			flags->fwidth = addmchar('0', var, flags->fwidth);
		}
		else
		{
			flags->fwidth = addmchar(' ', var, flags->fwidth);
			pf_addminp(flags, var, d);
		}
	}
	else
		pf_addminp(flags, var, d);
}

int			pf_ge(t_flags *flags, t_var *var, long double d, int count)
{
	char	*num;
	int		lenct;

	flags->len = flags->precision + 2;
	if ((num = pf_ftostr(d, flags)) == NULL)
		return (-1);
	pf_aground(num + flags->len, flags, d);
	lenct = pf_intlen(count, 10) - (count < -10);
	flags->fwidth -= flags->len + lenct + (lenct < 2) + 2
	+ (d < 0 || flags->space || flags->plus);
	flags->fwidth *= (flags->fwidth > 0);
	pf_addge(flags, var, d);
	addnstr(num, flags->len, var);
	pf_create(flags, var, count);
	if (flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	free(num);
	return (0);
}
