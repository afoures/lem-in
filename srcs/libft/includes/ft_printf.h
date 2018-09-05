/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:49:43 by rbalbous          #+#    #+#             */
/*   Updated: 2018/04/05 13:59:51 by rbalbous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <math.h>
# include <wchar.h>
# include <locale.h>
# include <langinfo.h>
# include <nl_types.h>
# include <time.h>
# include "libft.h"

# define BUFF_SIZE 4200
# define KEY "foufoureres"

typedef unsigned char		t_uint8;
typedef unsigned short int	t_uint16;
typedef unsigned int		t_uint32;
typedef unsigned long int	t_uint64;
typedef char				t_int8;
typedef short int			t_int16;
typedef int					t_int32;
typedef long int			t_int64;

typedef enum	e_conv
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_conv;

typedef struct	s_var
{
	t_int32		ret;
	t_uint32	index;
	t_uint32	error;
	t_uint32	dol;
	va_list		begin;
	t_uint32	count;
	t_uint32	bufindex;
	t_uint32	alwritten;
	t_int32		fd;
	char		*string;
	char		buf[BUFF_SIZE];
}				t_var;

typedef struct	s_flags
{
	t_uint8		minus : 1;
	t_uint8		plus : 1;
	t_uint8		hashtag : 1;
	t_uint8		space : 1;
	t_uint8		zero : 1;
	t_uint8		isp : 1;
	t_uint8		isw : 1;
	t_int32		precision;
	t_int32		fwidth;
	va_list		begin;
	va_list		pos;
	t_int8		tsep;
	t_int8		dpt;
	t_uint8		capx : 1;
	t_uint8		bigl;
	t_int8		cast;
	t_int32		len;
	t_conv		conv;
}				t_flags;

int				ft_printf(const char *str, ...);
int				ft_sprintf(char *dest, const char *str, ...);
void			pf_stringinit(t_var *var, char *dest);
int				ft_dprintf(int fd, const char *str, ...);
int				ft_vprintf(const char *str, va_list ap);
int				ft_vdprintf(int fd, const char *str, va_list ap);
int				ft_vsprintf(char *dest, const char *str, va_list ap);
int				parse(t_uint8 *str, t_var *var, va_list ap, int (*f[256])());
void			init_conv(int (*f[256])());
void			init_flags(int (*f[256])(), int i);
int				initialise_var(t_var *var, va_list ap, int (*f[256])()
				, char *str);
int				pf_parserror(t_var *var, va_list ap);

void			addchar(const char c, t_var *var);
void			addnstr(void *str, size_t len, t_var *var);
int				addnull(t_flags *flags, t_var *var);
int				addmchar(char c, t_var *var, int len);
int				pf_addzero(t_flags *flags, t_var *var);
int				pf_isnull(t_flags *flags, t_var *var);
int				pf_fzero(long double d, t_flags *flags, t_var *var);

int				pf_hashtag(t_flags *flags);
int				ft_minus(t_flags *flags);
int				ft_plus(t_flags *flags);
int				ft_preci(t_flags *flags, t_var *var, va_list ap
				, t_uint8 *str);
int				pf_fwidth(t_flags *flags, t_var *var, va_list ap
				, t_uint8 *str);
int				ft_space(t_flags *flags);
int				ft_zero(t_flags *flags);
int				pf_wildcard(t_flags *flags, t_var *var, va_list ap
				, t_uint8 *str);
int				pf_apostrophe(t_flags *flags);

int				pf_s(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_s(t_flags *flags, t_var *var, va_list ap);

int				len_one(wint_t c, t_var *var);
int				len_two(wint_t c, t_var *var);
int				len_three(wint_t c, t_var *var);
int				len_four(wint_t c, t_var *var);

int				pf_c(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_c(t_flags *flags, t_var *var, va_list ap);

int				pf_d(t_flags *flags, t_var *var, va_list ap);
int				pf_spe_d(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_d(t_flags *flags, t_var *var, va_list ap);
int				pf_hd(t_flags *flags, t_var *var, va_list ap);
int				pf_hhd(t_flags *flags, t_var *var, va_list ap);
int				pf_lld(t_flags *flags, t_var *var, va_list ap);
int				pf_jd(t_flags *flags, t_var *var, va_list ap);
int				pf_zd(t_flags *flags, t_var *var, va_list ap);

int				pf_u(t_flags *flags, t_var *var, va_list ap);
int				pf_spe_u(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_u(t_flags *flags, t_var *var, va_list ap);
int				pf_hhu(t_flags *flags, t_var *var, va_list ap);
int				pf_hu(t_flags *flags, t_var *var, va_list ap);
int				pf_llu(t_flags *flags, t_var *var, va_list ap);
int				pf_ju(t_flags *flags, t_var *var, va_list ap);
int				pf_zu(t_flags *flags, t_var *var, va_list ap);

int				pf_o(t_flags *flags, t_var *var, va_list ap);
int				pf_spe_o(t_flags *flags, t_var *var, va_list ap);
int				pf_hho(t_flags *flags, t_var *var, va_list ap);
int				pf_ho(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_o(t_flags *flags, t_var *var, va_list ap);
int				pf_llo(t_flags *flags, t_var *var, va_list ap);
int				pf_jo(t_flags *flags, t_var *var, va_list ap);
int				pf_zo(t_flags *flags, t_var *var, va_list ap);

int				pf_x(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_sp_x(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_lx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_llx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_hx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_hhx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_jx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_zx(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_cap_x(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);

int				pf_n(t_flags *flags, t_var *var, va_list ap);
int				pf_spe_n(t_var *var, va_list ap);
int				pf_hhn(t_var *var, va_list ap);
int				pf_hn(t_var *var, va_list ap);
int				pf_zn(t_var *var, va_list ap);
int				pf_ln(t_var *var, va_list ap);
int				pf_lln(t_var *var, va_list ap);
int				pf_jn(t_var *var, va_list ap);

int				pf_f(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_f(t_flags *flags, t_var *var, va_list ap);
int				pf_spe_cap_f(t_flags *flags, t_var *var, long double d);
int				pf_cap_l(t_flags *flags);
int				pf_fcreate(t_flags *flags, t_var *var, long double d,
				char width);
int				pf_infinite(long double d, t_flags *flags, t_var *var);
int				pf_infinitec(long double d, t_flags *flags, t_var *var);
int				pf_nan(t_flags *flags, t_var *var);
int				pf_nanc(t_flags *flags, t_var *var);

int				pf_e(t_flags *flags, t_var *var, va_list ap);
int				pf_spe_e(t_flags *flags, t_var *var, long double d, int count);
int				pf_cap_e(t_flags *flags, t_var *var, va_list ap);
int				pf_spe_cap_e(t_flags *flags, t_var *var, long double d,
				int count);
int				pf_tosc(long double *d);
void			pf_eround(char *str, t_flags *flags, t_var *var);
int				pf_ground(char *str, t_var *var);

int				pf_a(t_flags *flags, t_var *var, va_list ap);
int				pf_la(t_flags *flags, t_var *var, va_list ap);
char			*pf_ftoa_hexa(long double n, t_flags *flags);
void			pf_initoa(char modu[16]);
int				pf_cap_a(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_la(t_flags *flags, t_var *var, va_list ap);
int				pf_toa(long double *d, t_flags *flags);
int				pf_tola(long double *d);
int				pf_acreate(t_var *var, t_flags *flags, int count,
				int len_count);
int				pf_around(char *str, char *base, t_flags *flags, long double d);
int				pf_makea(t_flags *flags, t_var *var, long double d,
				int len_count);
int				pf_capazero(t_flags *flags, t_var *var, long double d);
int				pf_makecapa(t_flags *flags, t_var *var, long double d, int lc);
int				pf_capacreate(t_var *var, t_flags *flags, int count,
				int len_count);

int				pf_g(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_g(t_flags *flags, t_var *var, va_list ap);
char			*pf_ftostr(long double n, t_flags *flags);
int				pf_itostr(char *str, t_flags *flags, intmax_t n);
int				pf_ge(t_flags *flags, t_var *var, long double d, int count);
int				pf_gf(t_flags *flags, t_var *var, long double d);
int				pf_aground(char *str, t_flags *flags, long double d);

int				pf_b(t_flags *flags, t_var *var, va_list ap);
int				pf_r(t_flags *flags, t_var *var, va_list ap);
int				pf_k(t_flags *flags, t_var *var, va_list ap);
int				pf_m(t_flags *flags, t_var *var, va_list ap);
int				pf_w(t_flags *flags, t_var *var, va_list ap);
int				pf_cap_w(t_flags *flags, t_var *var, va_list ap);

int				pf_percent(t_flags *flags, t_var *var, va_list ap
				, t_uint8 *str);
int				pf_empty_d(t_flags *flags, t_var *var);
int				pf_empty_o(t_flags *flags, t_var *var);
int				pf_empty_u(t_flags *flags, t_var *var);
int				pf_empty_x(t_flags *flags, t_var *var, t_uint8 *str);
int				pf_empty_s(t_flags *flags, t_var *var);

int				pf_dollar(t_flags *flags, t_var *var, va_list ap, t_uint8 *str);
int				pf_dol_s(void);
int				pf_dol_l(t_flags *flags, t_var *var, t_uint8 *str);
int				pf_dol_h(t_flags *flags);
int				pf_none(t_flags *flags, t_var *var, t_uint8 *str);
int				pf_dol_f(t_flags *flags, t_var *var, t_uint8 *str);
int				pf_dol_bl(void);

int				pf_l(t_flags *flags, t_var *var, va_list ap
				, t_uint8 *str);
int				ft_j(t_flags *flags);
int				pf_h(t_flags *flags);
int				pf_z(t_flags *flags);
int				pf_q(t_flags *flags);

void			pf_itoa(intmax_t n, t_flags *flags, t_var *var);
int				pf_tsep(t_flags *flags, t_var *var, char *toa);
size_t			pf_intlen(intmax_t n, int base);

size_t			pf_uintlen(uintmax_t n, int base);
void			pf_uitoa_base(uintmax_t n, int base, t_flags *flags
				, t_var *var);
void			pf_ftoa(long double n, t_flags *flags, t_var *var);
int				pf_uitoa_hexa(uintmax_t n, t_flags *flags, t_var *var);
char			*pf_fltoa_hexa(long double n, t_flags *flags);
char			*pf_cuitoa_hexa(uintmax_t n, t_flags *flags);
int				pf_round(char *str, t_flags *flags, t_var *var);
void			pf_ftoa_neg(double n, t_flags *flags, t_var *var, int sc);
int				pf_azero(t_flags *flags, t_var *var, long double d);
void			pf_addminp(t_flags *flags, t_var *var, long double d);

int				pf_memcpy(void *dest, const void *src, int n);
#endif
