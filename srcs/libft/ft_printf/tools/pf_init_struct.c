/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:25:10 by rbalbous          #+#    #+#             */
/*   Updated: 2018/03/05 14:01:58 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_stringinit(t_var *var, char *dest)
{
	var->string = dest;
	var->string[0] = 0;
}

void		init_conv(int (*f[256])())
{
	f['s'] = pf_s;
	f['c'] = pf_c;
	f['S'] = pf_cap_s;
	f['p'] = pf_lx;
	f['d'] = pf_d;
	f['D'] = pf_cap_d;
	f['i'] = pf_d;
	f['o'] = pf_o;
	f['O'] = pf_cap_o;
	f['u'] = pf_u;
	f['U'] = pf_cap_u;
	f['x'] = pf_x;
	f['X'] = pf_cap_x;
	f['C'] = pf_cap_c;
	f['%'] = pf_percent;
	f['*'] = pf_wildcard;
	f['b'] = pf_b;
	f['f'] = pf_f;
	f['F'] = pf_cap_f;
	f['n'] = pf_n;
	f['e'] = pf_e;
	f['E'] = pf_cap_e;
	f['$'] = pf_dollar;
	f['\''] = pf_apostrophe;
	f['g'] = pf_g;
}

void		init_flags(int (*f[256])(), int i)
{
	while (++i < 256)
		f[i] = pf_percent;
	i = -1;
	f['0'] = ft_zero;
	f['.'] = ft_preci;
	f['+'] = ft_plus;
	f['-'] = ft_minus;
	f['#'] = pf_hashtag;
	f[' '] = ft_space;
	while (++i < 9)
		f['1' + i] = pf_fwidth;
	f['h'] = pf_h;
	f['l'] = pf_l;
	f['j'] = ft_j;
	f['z'] = pf_z;
	f['a'] = pf_a;
	f['A'] = pf_cap_a;
	f['L'] = pf_cap_l;
	f['q'] = pf_q;
	f['r'] = pf_r;
	f['k'] = pf_k;
	f['m'] = pf_m;
	f['w'] = pf_w;
	f['W'] = pf_cap_w;
	init_conv(f);
}

int			initialise_var(t_var *var, va_list ap, int (*f[256])(), char *str)
{
	if (str == NULL)
		return (-1);
	var->ret = 0;
	var->string = 0;
	var->index = -1;
	var->bufindex = 0;
	var->dol = 0;
	var->count = 0;
	var->error = 0;
	var->alwritten = 0;
	var->fd = 1;
	va_copy(var->begin, ap);
	ft_bzero(var->buf, BUFF_SIZE);
	if (f[0] == NULL)
	{
		init_flags(f, -1);
		f['G'] = pf_cap_g;
	}
	return (0);
}
