# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    conv.mk                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 21:09:17 by rbalbous          #+#    #+#              #
#    Updated: 2018/04/05 14:22:21 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf/conv

CONVS = pf_s.c \
		pf_cap_s.c
SPATH = ft_printf/conv/s
CONVS_PATH = $(addprefix $(SPATH)/, $(CONVS))
OBJ = $(addprefix $(OBJ_PATH)/, $(CONVS:.c=.o))

CONVC = pf_c.c \
		pf_cap_c.c
CPATH = ft_printf/conv/c
CONVC_PATH = $(addprefix ft_printf/conv/c/, $(CONVC))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVC:.c=.o))

CONVD = 	pf_d.c \
			pf_cap_d.c \
			pf_hd.c \
			pf_hhd.c \
			pf_lld.c \
			pf_zd.c \
			pf_jd.c
DPATH = ft_printf/conv/d
CONVD_PATH = $(addprefix ft_printf/conv/d/, $(CONVD))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVD:.c=.o))

CONVU = 	pf_u.c \
			pf_cap_u.c \
			pf_hhu.c \
			pf_hu.c \
			pf_llu.c \
			pf_ju.c \
			pf_zu.c
UPATH = ft_printf/conv/u
CONVU_PATH = $(addprefix ft_printf/conv/u/, $(CONVU))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVU:.c=.o))


CONVO =		pf_o.c \
			pf_hho.c \
			pf_ho.c \
			pf_cap_o.c \
			pf_llo.c \
			pf_jo.c \
			pf_zo.c
OPATH = ft_printf/conv/o
CONVO_PATH = $(addprefix ft_printf/conv/o/, $(CONVO))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVO:.c=.o))

CONVX =		pf_x.c \
			pf_cap_x.c \
			pf_llx.c \
			pf_lx.c \
			pf_hx.c \
			pf_hhx.c \
			pf_jx.c \
			pf_zx.c
XPATH = ft_printf/conv/x
CONVX_PATH = $(addprefix ft_printf/conv/x/, $(CONVX))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVX:.c=.o))

CONVB =		pf_b.c
BPATH = ft_printf/conv/b
CONVB_PATH = $(addprefix ft_printf/conv/b/, $(CONVB))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVB:.c=.o))

CONVF =		pf_f.c \
			pf_cap_f.c \
			pf_fl.c
FPATH = ft_printf/conv/f
CONVF_PATH = $(addprefix ft_printf/conv/f/, $(CONVF))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVF:.c=.o))

CONVE =		pf_e.c \
			pf_cap_e.c
EPATH = ft_printf/conv/e
CONVE_PATH = $(addprefix ft_printf/conv/e/, $(CONVE))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVE:.c=.o))

CONVG =		pf_g.c \
			pf_ge.c \
			pf_gf.c
GPATH = ft_printf/conv/g
CONVG_PATH = $(addprefix ft_printf/conv/g/, $(CONVG))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVG:.c=.o))

CONVN =		pf_n.c \
			pf_hn.c \
			pf_hhn.c \
			pf_lln.c \
			pf_ln.c \
			pf_jn.c \
			pf_zn.c
NPATH = ft_printf/conv/n
CONVN_PATH = $(addprefix ft_printf/conv/n/, $(CONVN))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVN:.c=.o))

CONVA =		pf_a.c \
			pf_la.c \
			pf_cap_a.c \
			pf_cap_la.c
APATH = ft_printf/conv/a
CONVA_PATH = $(addprefix ft_printf/conv/a/, $(CONVA))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVA:.c=.o))

CONVR =		pf_r.c
RPATH = ft_printf/conv/r
CONVR_PATH = $(addprefix ft_printf/conv/r/, $(CONVR))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVR:.c=.o))

CONVK =		pf_k.c
KPATH = ft_printf/conv/k
CONVK_PATH = $(addprefix ft_printf/conv/k/, $(CONVK))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVK:.c=.o))

CONVM =		pf_m.c
MPATH = ft_printf/conv/m
CONVM_PATH = $(addprefix ft_printf/conv/k/, $(CONVM))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVM:.c=.o))

CONVW =		pf_w.c \
			pf_cap_w.c
WPATH = ft_printf/conv/w
CONVW_PATH = $(addprefix ft_printf/conv/w/, $(CONVW))
OBJ += $(addprefix $(OBJ_PATH)/, $(CONVW:.c=.o))

$(OBJ_PATH)/%.o : $(SPATH)/%.c $(INCLUDES)/ft_printf.h
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(CPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(DPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)		

$(OBJ_PATH)/%.o : $(UPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(OPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(XPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(BPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(FPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(NPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(EPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(GPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(APATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(RPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(KPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(MPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
	
$(OBJ_PATH)/%.o : $(WPATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
