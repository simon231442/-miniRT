# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 15:04:08 by jsurian42         #+#    #+#              #
#    Updated: 2026/01/27 13:41:50 by jsurian42        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

################################################################################
#                               DIRECTORIES                                    #
################################################################################

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIB_DIR = lib

################################################################################
#                                MINIRT SRC                                    #
################################################################################

vpath	%.c src:src/mlx:src/parsing:src/error:src/debug:src/math:src/render

SOURCES :=	minirt.c \
			rt_error_put.c \
			rt_debug_scene_all_display.c \
			rt_debug_scene_ambient_display.c \
			rt_debug_scene_cam_display.c \
			rt_debug_scene_light_display.c \
			rt_debug_scene_shape_display.c \
			rt_parse.c \
			rt_parse_ambient.c \
			rt_parse_cam.c \
			rt_parse_light.c \
			rt_parse_shape_cylinder.c \
			rt_parse_shape_plane.c \
			rt_parse_shape_sphere.c \
			rt_parse_util_arg_free.c \
			rt_parse_util_atod.c \
			rt_parse_util_color.c \
			rt_parse_utils_get_int_color.c \
			rt_parse_util_line_clean.c \
			rt_parse_util_shape_free.c \
			rt_parse_util_vector.c \
			rt_mlx_init.c \
			rt_mlx_hook.c \
			rt_mlx_hook_key.c \
			rt_math_pixel_get_vec.c \
			rt_math_light_get_vec.c \
			rt_math_sphere_get_delta.c \
			rt_math_sphere_intersect.c \
			rt_math_plane_intersect.c \
			rt_math_cylinder_intersect.c \
			rt_math_shape_get_normal.c \
			rt_math_sphere_get_normal.c \
			rt_math_cylinder_get_normal.c \
			rt_math_get_intersect_point.c \
			rt_math_utils_vec_normalize.c \
			rt_math_utils_vec_length.c \
			rt_math_utils_vec_dot.c \
			rt_math_utils_vec_sub.c \
			rt_math_utils_get_cosinus.c\
			rt_math_utils_vec_cross.c \
			rt_math_utils_vec_add.c \
			rt_math_utils_vec_multi_scale.c \
			rt_math_utils_point_distance.c \
			rt_render.c \
			rt_render_pixel_get_addr.c \
			rt_render_pixel_get_color.c \
			rt_render_shape_intersect.c \
			rt_render_light_get_intensity.c \
			rt_render_shadow_intersect.c \
			rt_render_pixel_get_ret_color.c \


.DEFAULT_GOAL := all

################################################################################
#                                 LIBRARY                                      #
################################################################################

lib/libft/libft.a:
	$(MAKE) -C lib/libft bonus
lib/get_next_line/get_next_line.a:
	$(MAKE) -C lib/get_next_line
lib/minilibx-linux/libmlx.a:
	$(MAKE) -C lib/minilibx-linux

LIB_LINK = -Ilib/libft -Ilib/minilibx-linux -Ilib/get_next_line

################################################################################
#                             COMPILER OPTIONS                                 #
################################################################################

UNAME_N := $(shell uname -n)
ifeq ($(UNAME_N),Arch-Jules)
	CC	:= tcc
else
	CC	:= gcc
endif

CFLAGS		:= -g -Wall -Werror -Wextra
CPPFLAGS	:= -Iincludes $(LIB_LINK)
MLXFLAGS 	:= -Llib/minilibx-linux/ -lmlx -lXext -lX11 -lm

LIBFT		:= lib/libft/libft.a
GNL			:= lib/get_next_line/get_next_line.a
MLX			:= lib/minilibx-linux/libmlx.a

OBJETS		:= $(SOURCES:%.c=$(OBJ_DIR)/%.o)

################################################################################
#                              TARGETS & RULES                                 #
################################################################################

$(NAME) : $(OBJETS) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(OBJETS) $(LIBFT) $(GNL) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
#@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

.PHONY: all
all : $(NAME)

.PHONY: clean
clean : 
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C lib/libft clean
	$(MAKE) -C lib/get_next_line clean
	$(MAKE) -C lib/minilibx-linux clean

.PHONY: fclean
fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C lib/libft fclean
	$(MAKE) -C lib/get_next_line fclean

.PHONY: re
re : fclean all
