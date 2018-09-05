# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    flags.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 21:50:54 by rbalbous          #+#    #+#              #
#    Updated: 2018/04/05 14:22:34 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEN =		ft_j.c \
			pf_l.c \
			pf_h.c \
			pf_z.c \
			pf_q.c \
			pf_cap_l.c
LEN_PATH = ft_printf/flags/length
FLAGS_LEN_PATH = $(addprefix ft_printf/flags/length/, $(LEN))
OBJ += $(addprefix $(OBJ_PATH)/, $(LEN:.c=.o))	
		
OTH =		pf_hashtag.c \
			ft_minus.c \
			ft_plus.c \
			ft_preci.c \
			pf_fwidth.c \
			ft_space.c \
			ft_zero.c \
			pf_percent.c \
			pf_empty.c \
			pf_dollar.c \
			pf_dol.c \
			pf_apostrophe.c \
			pf_wildcard.c 
OTH_PATH = ft_printf/flags/others
FLAGS_OTH_PATH = $(addprefix ft_printf/flags/others/, $(OTH))
OBJ += $(addprefix $(OBJ_PATH)/, $(OTH:.c=.o))

$(OBJ_PATH)/%.o : $(LEN_PATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)

$(OBJ_PATH)/%.o : $(OTH_PATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)
