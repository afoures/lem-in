# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoures <afoures@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/23 15:23:24 by rbalbous          #+#    #+#              #
#    Updated: 2018/06/12 17:17:02 by afoures          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
FLAGS = -Wall -Wextra -Werror -Ofast

SRCS =	main.c \
		flags.c \
		parser.c \
		read.c \
		check_valid.c \
		get_rooms.c \
		get_links.c \
		check_rooms.c \
		exit.c \
		errors.c \
		algo.c \
		output.c \
		solver.c \
		antflow.c \
		colors.c \
		debug.c \
		print_colored_text.c \
		lmatador.c \
		display.c

SRCS_PATH = srcs
OBJ = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))
OBJ_PATH = obj

INCLUDES = includes

LIB_PATH = srcs/libft
LIB = $(LIB_PATH)/libft.a

all :		$(NAME)

$(NAME) :	$(OBJ) $(LIB)
			$(CC) -o $@ $^ $(FLAGS)

$(LIB) :
			make -j -C $(LIB_PATH)

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.c $(INCLUDES)/lem_in.h
			@mkdir -p $(OBJ_PATH)
			$(CC) -o $@ -c $< -I $(INCLUDES) -I $(LIB_PATH)/includes $(FLAGS)

clean :
			make -C $(LIB_PATH) clean
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)
			rm -f $(LIB)

re : 
			make fclean 
			make all

.PHONY : all clean fclean re
