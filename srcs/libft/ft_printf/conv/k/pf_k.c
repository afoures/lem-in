/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_k.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 18:52:42 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/17 19:45:18 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		g_day[7][4] =
{
	"Sun",
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat"
};

static char		g_mon[12][4] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

int		pf_k(t_flags *flags, t_var *var, va_list ap)
{
	struct tm	*ti;
	char		date[25];

	(void)flags;
	(void)var;
	ti = va_arg(ap, struct tm*);
	ft_sprintf(date, "%s %s %2d %.2d:%.2d:%.2d %.4d", g_day[ti->tm_wday]
		, g_mon[ti->tm_mon], ti->tm_mday, ti->tm_hour, ti->tm_min, ti->tm_sec
		, ti->tm_year + 1900);
	addnstr(date, 24, var);
	return (0);
}
