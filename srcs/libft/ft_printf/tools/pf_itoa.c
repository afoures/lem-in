/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 15:00:03 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/03 21:39:10 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_intlen(intmax_t n, int base)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count);
}

int		pf_tsep(t_flags *flags, t_var *var, char *toa)
{
	int		i;
	int		j;
	int		lenstr;
	char	str[25];

	i = 1;
	j = 1;
	lenstr = flags->len + (flags->len / 3) - (flags->len % 3 == 0);
	while (i < lenstr + 1)
	{
		if (i % 4 == 0 && i != 0)
			str[lenstr - i] = flags->tsep;
		else
		{
			str[lenstr - i] = toa[flags->len - j];
			j++;
		}
		i++;
	}
	addnstr(str, lenstr, var);
	return (1);
}

void	pf_itoa(intmax_t n, t_flags *flags, t_var *var)
{
	char		toa[25];
	size_t		count;

	if (n == 0)
		return (addchar('0', var));
	count = flags->len;
	while (count-- > 0)
	{
		toa[count] = -(n % 10) + 48;
		n /= 10;
	}
	if (!flags->tsep)
		addnstr(toa, flags->len, var);
	else
		pf_tsep(flags, var, toa);
}
