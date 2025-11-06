# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/05 17:08:16 by jsurian42         #+#    #+#              #
#    Updated: 2025/11/06 22:36:57 by jsurian42        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := get_next_line.a

SOURCES := get_next_line.c \
		   get_next_line_utils.c

.DEFAULT_GOAL := all

CC := gcc
CFLAGS		:= -g -Wall -Werror -Wextra

OBJETS		:= $(SOURCES:%.c=%.o)

$(NAME) : $(OBJETS)
	@ar rcs $(NAME) $(OBJETS)

.PHONY: all
all : $(NAME)

.PHONY: clean
clean : 
	$(RM) *.o

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)

.PHONY: re
re : fclean all
