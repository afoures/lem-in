/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:28:48 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/16 15:25:47 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_uintlen(uintmax_t n, int base)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

void	pf_uitoa_base(uintmax_t n, int base, t_flags *flags, t_var *var)
{
	char		toa[25];
	size_t		count;

	if (n == 0)
		return (addchar('0', var));
	count = flags->len;
	while (count-- > 0)
	{
		toa[count] = n % base + 48;
		n /= base;
	}
	if (!flags->tsep)
		addnstr(toa, flags->len, var);
	else
		pf_tsep(flags, var, toa);
}
