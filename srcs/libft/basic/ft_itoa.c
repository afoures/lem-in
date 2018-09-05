/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:50:05 by rbalbous          #+#    #+#             */
/*   Updated: 2017/12/18 18:18:37 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	sign;
	size_t	tn;
	size_t	count;

	count = 0;
	tn = (n < 0) ? -n : n;
	sign = (n < 0) ? 1 : 0;
	if (n == 0)
		return (ft_memset(ft_strnew(1), '0', 1));
	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	count = ft_intlen(n);
	if ((str = ft_strnew(count)) == NULL)
		return (NULL);
	tn = (n < 0) ? -n : n;
	while (count-- > sign)
	{
		str[count] = (tn % 10) + 48;
		tn /= 10;
	}
	if (sign > 0)
		str[0] = '-';
	return (str);
}
