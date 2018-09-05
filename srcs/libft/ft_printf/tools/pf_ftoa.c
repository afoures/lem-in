/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 22:08:43 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/03 18:51:36 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_ftoa(long double n, t_flags *flags, t_var *var)
{
	char	str[25];
	int		i;
	int		count;

	i = 1;
	pf_itoa((intmax_t)(n * (2 * (n < 0) - 1)), flags, var);
	if (flags->dpt == 0)
		flags->dpt = '.';
	str[0] = flags->dpt;
	count = flags->precision + 2 +
	flags->hashtag * (!flags->precision);
	while (i < count)
	{
		n = (n - (intmax_t)n) * 10 * (-2 * (n < 0) + 1);
		str[i] = (intmax_t)n + '0';
		i++;
	}
	str[i] = 0;
	addnstr(str, count, var);
}

char	*pf_ftostr(long double n, t_flags *flags)
{
	char	*str;
	int		i;
	int		count;

	if (!(str = ft_memalloc(flags->len + 1)))
		return (NULL);
	count = pf_itostr(str, flags, (intmax_t)(n * (2 * (n < 0) - 1)));
	i = count;
	while (i < flags->len + 1)
	{
		n = (n - (intmax_t)n) * 10 * (-2 * (n < 0) + 1);
		str[i] = (intmax_t)n + '0';
		i++;
	}
	str[i] = 0;
	return (str);
}

int		pf_itostr(char *str, t_flags *flags, intmax_t n)
{
	int		count;
	int		tmp;

	if (n == 0)
	{
		str[0] = '0';
		str[1] = '.';
		return (2);
	}
	count = pf_intlen(n, 10) - 1;
	tmp = count;
	if (count > flags->len)
		count = flags->len + 1;
	str[count] = '.';
	while (count-- > 0)
	{
		str[count] = -(n % 10) + 48;
		n /= 10;
	}
	return (tmp + 1);
}
