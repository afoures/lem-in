/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:21:11 by rbalbous          #+#    #+#             */
/*   Updated: 2018/02/17 15:58:59 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countprec(t_flags *flags, char *str)
{
	int		i;

	i = 15 + flags->bigl;
	if (flags->isp)
	{
		flags->len = (flags->precision + 3 - (flags->bigl));
		return (flags->precision + 3 - (flags->bigl));
	}
	while (str[i] == '0')
	{
		i--;
	}
	i += 1 * (i != 0);
	if (i == 2)
		flags->precision = -1;
	flags->len = i;
	return (i);
}

char		*pf_ftoa_hexa(long double n, t_flags *flags)
{
	char			*str;
	int				i;
	static char		modu[16];
	int				flag;

	i = 2;
	if (!modu[0])
		pf_initoa(modu);
	if (!(str = ft_memalloc(flags->precision + 4
	+ (flags->precision == -1 * (!flags->bigl)))))
		return (NULL);
	str[0] = modu[(int)(n * (1 - 2 * (n < 0)))] -
	flags->capx * (int)((n * (1 - 2 * (n < 0)) > 10)) * 32;
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[1] = flags->dpt;
	while (i < flags->precision + 4 + (flags->precision == -1 * (!flags->bigl)))
	{
		n = (n - (intmax_t)n) * 16 * (-2 * (n < 0) + 1);
		flag = flags->capx * (((intmax_t)n % 16) > 9 && i != 0);
		str[i] = modu[(intmax_t)n] - flag * 32;
		i++;
	}
	countprec(flags, str);
	return (str);
}
