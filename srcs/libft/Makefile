# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoures <afoures@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 17:34:45 by rbalbous          #+#    #+#              #
#    Updated: 2018/06/12 17:17:08 by afoures          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast

INCLUDES = includes
OBJ_PATH = obj

include ft_printf/conv/conv.mk
include ft_printf/flags/flags.mk
include	ft_printf/tools/tools.mk
include basic/libft.mk

all : $(NAME)

$(NAME) :	$(OBJ)
			mkdir -p $(OBJ_PATH)
			ar rc $(NAME) $^
			ranlib $(NAME)
			@echo "\033[33mlib done\033[m"
			
clean :
			rm -f $(OBJ)

fclean : 	clean
			rm -f $(NAME)
		
re :
	make fclean
	make all

.PHONY: all clean fclean re
