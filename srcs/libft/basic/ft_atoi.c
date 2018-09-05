/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 14:56:24 by raf               #+#    #+#             */
/*   Updated: 2017/11/07 13:11:58 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int count_sign[2];

	count_sign[0] = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	count_sign[1] = (*str == '-' || *str == '+') ? -(*(str++) - 44) : 1;
	while (*str >= '0' && *str <= '9')
		count_sign[0] = count_sign[0] * 10 + *(str++) - '0';
	return (count_sign[0] * count_sign[1]);
}
