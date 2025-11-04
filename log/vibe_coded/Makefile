# Makefile for vibe_coded subset (place this file in log/vibe_coded/)

NAME := ../../miniRT

CC := cc
CFLAGS := -Wall -Wextra -Werror

INCLUDES := -Iincludes -Ilib/libft -Ilib/get_next_line -Ilib/minilibx-linux
LIBFT_DIR := lib/libft
MLX_DIR := lib/minilibx-linux

SRCS_DIR := src/core
SRCS := \
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
	lib/get_next_line/get_next_line.c \
	lib/get_next_line/get_next_line_utils.c

OBJS := $(SRCS:.c=.o)

MLX_FLAGS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBS := $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_DIR)/libmlx.a:
	MLX_SKIP_TEST=1 $(MAKE) -C $(MLX_DIR)

.PHONY: clean fclean re libft mlx

clean:
	$(MAKE) -C $(LIBFT_DIR) clean || true
	$(MAKE) -C $(MLX_DIR) clean || true
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean || true
	$(MAKE) -C $(MLX_DIR) clean || true
	rm -f $(NAME)

re: fclean all
