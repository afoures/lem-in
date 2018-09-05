/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_gf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 19:21:22 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/22 14:52:40 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_agfround(char *str, t_flags *flags, long double d)
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
			*str += 1;
		else
			*(--str) += 1;
	}
	while (*(--str) == '0' && (*(str + 1) == '0' || *(str - 1) == '.')
	&& !flags->hashtag)
		flags->len--;
	if (*str == '.' && (pf_intlen((intmax_t)d, 10) - (d < 0)
	== (size_t)flags->len - 1) && !flags->hashtag)
		flags->len--;
	return (0);
}

void		pf_addgf(t_flags *flags, t_var *var, long double d)
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

void		pf_add_apo(t_flags *flags, t_var *var, char *num, int apo)
{
	int		i;
	int		len;
	int		index;

	i = apo + flags->len;
	index = 0;
	len = 0;
	while (len < flags->len)
	{
		if (num[len] == '.')
			break ;
		len++;
	}
	while (i > 0)
	{
		if (len > 0 && len % 3 == 0 && i != flags->len + apo)
			addchar(flags->tsep, var);
		else
		{
			addchar(num[index], var);
			index++;
		}
		len--;
		i--;
	}
}

int			pf_gf(t_flags *flags, t_var *var, long double d)
{
	char	*num;
	int		apo;

	flags->len = flags->precision + 2;
	if (pf_intlen((intmax_t)d, 10) == (size_t)flags->len - 1 && !flags->hashtag)
		flags->len--;
	if ((num = pf_ftostr(d, flags)) == NULL)
		return (-1);
	pf_agfround(num + flags->len, flags, d);
	apo = pf_intlen((intmax_t)d, 10) * (flags->tsep != 0);
	apo = ((apo / 3) - (apo % 3 == 0)) * (flags->tsep != 0);
	flags->fwidth -= flags->len + (d < 0 || flags->space || flags->plus) + apo;
	flags->fwidth *= (flags->fwidth > 0);
	pf_addgf(flags, var, d);
	if (!flags->tsep)
		addnstr(num, flags->len, var);
	else
		pf_add_apo(flags, var, num, apo);
	if (flags->minus)
		flags->fwidth = addmchar(' ' + 16 * flags->zero, var, flags->fwidth);
	free(num);
	return (0);
}
