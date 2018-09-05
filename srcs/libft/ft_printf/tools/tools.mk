# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tools.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 22:07:59 by rbalbous          #+#    #+#              #
#    Updated: 2018/04/05 14:22:38 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TOOLS =		ft_printf.c \
			ft_sprintf.c \
			ft_dprintf.c \
			ft_vprintf.c \
			ft_vdprintf.c \
			ft_vsprintf.c \
			add.c \
			ft_parse.c \
			pf_itoa.c \
			pf_uitoa.c \
			pf_ftoa.c \
			pf_ftoa_hexa.c \
			pf_uitoa_hexa.c \
			pf_memcpy.c \
			pf_init_struct.c
TOOLS_PATH = ft_printf/tools

OBJ += $(addprefix $(OBJ_PATH)/, $(TOOLS:.c=.o))

$(OBJ_PATH)/%.o : $(TOOLS_PATH)/%.c $(INCLUDES)/ft_printf.h
	@$(CC) -o $@ -c $< -I $(INCLUDES) $(CFLAGS)	
