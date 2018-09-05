/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_m.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:35:57 by rbalbous          #+#    #+#             */
/*   Updated: 2018/01/15 17:18:24 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_mcreate(t_flags *flags, unsigned char *adr, char *mod, char *string)
{
	int		ind;
	int		skip;
	int		fpre;

	ind = 0;
	skip = 0;
	fpre = flags->fwidth * flags->precision;
	while (ind < flags->len || ind % fpre == 0)
	{
		if (ind && ind % fpre == 0 && skip == 0 && (skip = 1))
			*string = '\n';
		else if (ind && ind % flags->precision == 0 && skip == 0 && (skip = 1))
			*string = ' ';
		else
		{
			*(string++) = mod[((int)*adr / 16) % 16];
			*string = mod[((int)*(adr++) % 16)];
			ind++;
			skip = 0;
		}
		string++;
	}
	return (1);
}

int		pf_m(t_flags *flags, t_var *var, va_list ap)
{
	unsigned char	*adr;
	char			*use;
	int				ind;
	char			*string;
	int				leng;

	flags->fwidth += 8 * (flags->fwidth < 1);
	flags->precision += 3 * (!flags->isp) + 2 * (flags->precision == 0);
	flags->precision += (flags->precision + flags->fwidth == 2) * 1;
	adr = va_arg(ap, unsigned char*);
	flags->len = va_arg(ap, int);
	leng = flags->len * 2 + (flags->len / flags->precision + 1);
	if (!(string = malloc(sizeof(*string) * leng)))
		return (-1);
	use = string;
	pf_mcreate(flags, adr, "0123456789abcdef", string);
	ind = 1 * ((flags->len * 2) % flags->precision == 0);
	addnstr(use, flags->len * 2 + (flags->len / flags->precision) - ind, var);
	free(string);
	return (0);
}
