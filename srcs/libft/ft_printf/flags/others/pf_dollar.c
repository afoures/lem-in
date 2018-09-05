/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 12:44:11 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/05 14:28:36 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_va_inc(t_var *var, va_list temp, int *doll, int len)
{
	var->dol = len + 1;
	while (len > 0)
	{
		if (doll[len] == 's')
			va_arg(temp, char*);
		else if (doll[len] == 'l')
			va_arg(temp, long);
		else if (doll[len] == 'L')
			va_arg(temp, long long);
		else if (doll[len] == 'f')
			va_arg(temp, double);
		else if (doll[len] == 'F')
			va_arg(temp, long double);
		else if (doll[len] == 'n')
			va_arg(temp, int);
		len--;
	}
	var->count--;
	return (0);
}

int		pf_initlar(int (*lar[256])(), t_var *var)
{
	var->index = 0;
	while (++var->index < 256)
		lar[var->index] = pf_none;
	lar['h'] = pf_dol_h;
	lar['l'] = pf_dol_l;
	lar['s'] = pf_dol_s;
	lar['f'] = pf_dol_f;
	lar['g'] = pf_dol_f;
	lar['e'] = pf_dol_f;
	lar['a'] = pf_dol_f;
	lar['w'] = pf_dol_s;
	var->index = 1;
	return (0);
}

int		pf_initdol(t_flags *flags, t_var *var, t_uint8 *str, int *doll)
{
	int			ret;
	int			in;
	int			stock;
	static int	(*lar[256])() = {NULL};

	stock = var->index;
	in = pf_initlar(lar, var);
	while (str[var->index])
	{
		ret = lar[(int)str[var->index]](flags, var, str);
		if (ret == -1)
		{
			if (doll[in] == 0)
				doll[in] = 'n';
			flags->conv = none;
			in++;
		}
		if (ret > 1)
			doll[in] = ret;
		var->index++;
	}
	if (doll[in] == 0)
		doll[in] = 'n';
	var->index = stock;
	return (1);
}

int		pf_nbdol(t_uint8 *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i - 1] != '%' && str[i + 1] != '%')
			count++;
		i++;
	}
	return (count);
}

int		pf_dollar(t_flags *flags, t_var *var, va_list ap, t_uint8 *str)
{
	t_uint32	len;
	static int	*doll;
	va_list		temp;

	if (!doll)
	{
		var->count = pf_nbdol(str);
		if (!(doll = ft_memalloc((size_t)(var->count) * 4)))
			return (-1);
		pf_initdol(flags, var, str, doll);
	}
	len = flags->fwidth - (1 * (flags->fwidth > 0));
	va_copy(temp, var->begin);
	pf_va_inc(var, temp, doll, len);
	va_copy(ap, temp);
	va_end(temp);
	var->index++;
	if (var->count == 0)
	{
		free(doll);
		doll = 0;
	}
	return (1);
}
