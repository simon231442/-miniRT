# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:04:08 by jsurian42         #+#    #+#              #
#    Updated: 2025/11/04 16:37:19 by jsurian42        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

vpath	%.c src

SOURCES := minirt.c

#libft + gnl a ajoute

.DEFAULT_GOAL := all

UNAME_N := $(shell uname -n)
ifeq ($(UNAME_N),Arch-Jules)
	CC	:= tcc
else
	CC	:= gcc
endif

CFLAGS		:= -g -Wall -Werror -Wextra
CPPFLAGS	:= -Iincludes

OBJETS		:= $(SOURCES:%.c=%.o)

#objet dans dossier

$(NAME) : $(OBJETS)
	$(CC) $(CFLAGS) $(OBJETS) -o $(NAME)

.PHONY: all
all : $(NAME)

.PHONY: clean
clean : 
	$(RM) *.o

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)
#clean libft/gnl

.PHONY: re
re : fclean all
