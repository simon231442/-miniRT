# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: github <github@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 00:00:00 by github            #+#    #+#              #
#    Updated: 2025/11/03 00:00:00 by github           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= miniRT

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

INCLUDES	:= -Ivibe_coded/includes -Ivibe_coded/lib/libft -Ivibe_coded/lib/get_next_line -Ivibe_coded/lib/minilibx-linux
LIBFT_DIR	:= vibe_coded/lib/libft
MLX_DIR	:= vibe_coded/lib/minilibx-linux

LIBFT		:= $(LIBFT_DIR)/libft.a
MLX		:= $(MLX_DIR)/libmlx.a

SRCS_DIR	:= vibe_coded/src/core
SRCS		:= \
	$(SRCS_DIR)/rt_entry_main.c \
	$(SRCS_DIR)/rt_core_main.c \
	$(SRCS_DIR)/rt_application.c \
	$(SRCS_DIR)/rt_camera_configure.c \
	$(SRCS_DIR)/rt_render_scene.c \
	$(SRCS_DIR)/rt_intersect_scene.c \
	$(SRCS_DIR)/rt_intersect_sphere.c \
	$(SRCS_DIR)/rt_intersect_plane.c \
	$(SRCS_DIR)/rt_intersect_cylinder.c \
	$(SRCS_DIR)/rt_scene_init.c \
	$(SRCS_DIR)/rt_scene_loader.c \
	$(SRCS_DIR)/rt_scene_parse_ambient.c \
	$(SRCS_DIR)/rt_scene_parse_camera.c \
	$(SRCS_DIR)/rt_scene_parse_light.c \
	$(SRCS_DIR)/rt_scene_parse_sphere.c \
	$(SRCS_DIR)/rt_scene_parse_plane.c \
	$(SRCS_DIR)/rt_scene_parse_cylinder.c \
	$(SRCS_DIR)/rt_scene_parser_utils_numeric.c \
	$(SRCS_DIR)/rt_scene_parser_utils_color.c \
	$(SRCS_DIR)/rt_math_vec3_basic.c \
	$(SRCS_DIR)/rt_math_vec3_ops.c \
	$(SRCS_DIR)/rt_math_vec3_norm.c \
	$(SRCS_DIR)/rt_color_basic.c \
	$(SRCS_DIR)/rt_color_ops.c \
	$(SRCS_DIR)/rt_color_convert.c \
	$(SRCS_DIR)/rt_error.c \
	vibe_coded/lib/get_next_line/get_next_line.c \
	vibe_coded/lib/get_next_line/get_next_line_utils.c

OBJS		:= $(SRCS:.c=.o)

MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBS		:= $(LIBFT) $(MLX)

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	MLX_SKIP_TEST=1 $(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus