/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uitoa_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 20:40:24 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/04 00:39:33 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_initoa(char modu[16])
{
	modu[0] = '0';
	modu[1] = '1';
	modu[2] = '2';
	modu[3] = '3';
	modu[4] = '4';
	modu[5] = '5';
	modu[6] = '6';
	modu[7] = '7';
	modu[8] = '8';
	modu[9] = '9';
	modu[10] = 'a';
	modu[11] = 'b';
	modu[12] = 'c';
	modu[13] = 'd';
	modu[14] = 'e';
	modu[15] = 'f';
}

int		pf_uitoa_hexa(uintmax_t n, t_flags *flags, t_var *var)
{
	char			*str;
	static char		modu[16];
	int				flag;
	int				len;

	if (!modu[0])
		pf_initoa(modu);
	if (n == 0)
	{
		addchar('0', var);
		return (0);
	}
	if ((str = ft_strnew(flags->len)) == NULL)
		return (-1);
	len = flags->len;
	while (flags->len-- > 0)
	{
		flag = flags->capx * ((n & 15) > 9);
		str[flags->len] = modu[n & 15] - flag * 32;
		n /= 16;
	}
	addnstr(str, len, var);
	free(str);
	return (0);
}
