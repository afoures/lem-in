/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:33:39 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/05 12:20:49 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_buff(t_var *var)
{
	if (!var->string)
		write(var->fd, var->buf, var->bufindex);
	else
		pf_memcpy(var->string, var->buf, var->bufindex);
	var->alwritten += var->bufindex;
	var->bufindex = 0;
}

int		addnull(t_flags *flags, t_var *var)
{
	int n;

	n = 6;
	if (flags->precision < 6 && flags->isp)
		n = flags->precision;
	if (var->bufindex + n > BUFF_SIZE - 1)
		clean_buff(var);
	addnstr("(null)", n, var);
	return (0);
}

int		addmchar(char c, t_var *var, int len)
{
	while (len-- > 0)
	{
		var->buf[var->bufindex] = c;
		var->bufindex++;
		if (var->bufindex == BUFF_SIZE - 1)
			clean_buff(var);
	}
	return (0);
}

void	addchar(const char c, t_var *var)
{
	if (var->bufindex + 1 > BUFF_SIZE - 1)
		clean_buff(var);
	var->buf[var->bufindex] = c;
	var->bufindex++;
	return ;
}

void	addnstr(void *str, size_t len, t_var *var)
{
	size_t	i;
	char	*tmp;

	tmp = str;
	i = 0;
	while (len > i)
	{
		var->buf[var->bufindex] = tmp[i];
		i++;
		var->bufindex++;
		if (var->bufindex + len > BUFF_SIZE - 1)
			clean_buff(var);
	}
	return ;
}
