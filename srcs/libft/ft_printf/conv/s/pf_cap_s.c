/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cap_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:36:20 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/12 16:08:09 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_wcharlen(wchar_t *tmp, t_flags *flags, int stock[1000])
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] > 0x10FFFF || (0xD800 <= tmp[i] && tmp[i] <= 0xDFFF)
		|| (MB_CUR_MAX == 1 && tmp[i] > 255 && flags->precision != 1)
		|| tmp[i] < 0)
			return (-1);
		stock[i] = 0;
		stock[i] = 1 * (!(tmp[i] >> (7 + (MB_CUR_MAX == 1))));
		stock[i] += 2 * (!(tmp[i] >> 11) && !stock[i]);
		stock[i] += 3 * (!(tmp[i] >> 16) && !stock[i]);
		stock[i] += 4 * (!(tmp[i] >> 21) && !stock[i]);
		if (flags->precision < 0 || flags->precision >= flags->len + stock[i])
			flags->len += stock[i];
		else
			return (1);
		i++;
	}
	return (1);
}

int		pf_stockit(t_flags *flags, t_var *var, wchar_t *tmp, int stock[1000])
{
	static int	(*u[4])() = {len_one, len_two, len_three, len_four};
	int			i;

	i = 0;
	while (tmp[i])
	{
		flags->len -= stock[i];
		if (flags->len < 0)
			return (0);
		u[stock[i] - 1](tmp[i], var);
		i++;
	}
	return (1);
}

int		pf_addit(t_flags *flags, t_var *var, wchar_t *tmp, int stock[1000])
{
	char		width;

	width = ' ' + 16 * flags->zero;
	if (flags->minus == 0)
	{
		flags->fwidth = addmchar(width, var, flags->fwidth);
		pf_stockit(flags, var, tmp, stock);
	}
	else
	{
		pf_stockit(flags, var, tmp, stock);
		flags->fwidth = addmchar(width, var, flags->fwidth);
	}
	return (0);
}

int		pf_cap_s(t_flags *flags, t_var *var, va_list ap)
{
	wchar_t		*tmp;
	int			stock[1000];

	tmp = va_arg(ap, wchar_t*);
	if (tmp == NULL)
		return (pf_isnull(flags, var));
	if (pf_wcharlen(tmp, flags, stock) == -1)
		return (-1);
	flags->fwidth -= flags->len;
	flags->fwidth *= (flags->fwidth > 0);
	pf_addit(flags, var, tmp, stock);
	return (0);
}
