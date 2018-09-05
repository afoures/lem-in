/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:22:09 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/13 20:04:28 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_len_n(int (*len_n[7])())
{
	len_n[0] = pf_spe_n;
	len_n[1] = pf_hhn;
	len_n[2] = pf_hn;
	len_n[3] = pf_ln;
	len_n[4] = pf_lln;
	len_n[5] = pf_jn;
	len_n[6] = pf_zn;
}

int			pf_n(t_flags *flags, t_var *var, va_list ap)
{
	static int	(*len_n[7])();

	(void)flags;
	if (len_n[0] == NULL)
		init_len_n(len_n);
	return (len_n[flags->conv](var, ap));
}

int			pf_spe_n(t_var *var, va_list ap)
{
	int		*tmp;

	tmp = va_arg(ap, int*);
	*tmp = var->bufindex + 1;
	return (0);
}
