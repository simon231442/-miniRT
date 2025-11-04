/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_application.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "libft.h"
#include "rt_application.h"
#include "rt_render.h"
#include "rt_scene.h"
#include "rt_error.h"

static int	rt_application_close(t_context *ctx)
{
	rt_core_application_destroy(ctx);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	rt_application_expose(t_context *ctx)
{
	mlx_put_image_to_window(ctx->mlx, ctx->window, ctx->image, 0, 0);
	return (0);
}

static int	rt_application_key(int keycode, t_context *ctx)
{
	if (keycode == 65307)
		rt_application_close(ctx);
	return (0);
}

static int	rt_application_setup_mlx(t_context *ctx)
{
	ctx->mlx = mlx_init();
	if (ctx->mlx == NULL)
		return (rt_error("Failed to init MLX"));
	ctx->window = mlx_new_window(ctx->mlx, RT_IMAGE_WIDTH,
		RT_IMAGE_HEIGHT, "miniRT vibe");
	if (ctx->window == NULL)
		return (rt_error("Failed to create window"));
	ctx->image = mlx_new_image(ctx->mlx, RT_IMAGE_WIDTH, RT_IMAGE_HEIGHT);
	if (ctx->image == NULL)
		return (rt_error("Failed to create image"));
	ctx->buffer = mlx_get_data_addr(ctx->image, &ctx->bits_per_pixel,
		&ctx->size_line, &ctx->endian);
	if (ctx->buffer == NULL)
		return (rt_error("Failed to get buffer"));
	return (0);
}

static int	rt_application_scene(t_context *ctx, const char *path)
{
	rt_scene_init(&ctx->scene);
	if (rt_scene_load(&ctx->scene, path) != 0)
		return (1);
	return (0);
}

int	rt_core_application_start(t_context *ctx, const char *path)
{
	if (ctx == NULL)
		return (rt_error("Context missing"));
	ft_bzero(ctx, sizeof(t_context));
	if (rt_application_scene(ctx, path) != 0)
	{
		rt_core_application_destroy(ctx);
		return (1);
	}
	if (rt_application_setup_mlx(ctx) != 0)
	{
		rt_core_application_destroy(ctx);
		return (1);
	}
	if (rt_render_scene(ctx) != 0)
	{
		rt_core_application_destroy(ctx);
		return (1);
	}
	mlx_hook(ctx->window, 17, 0, (int (*)(void *))rt_application_close, ctx);
	mlx_key_hook(ctx->window, (int (*)(int, void *))rt_application_key, ctx);
	mlx_expose_hook(ctx->window, (int (*)(void *))rt_application_expose, ctx);
	mlx_loop(ctx->mlx);
	return (0);
}

void	rt_core_application_destroy(t_context *ctx)
{
	if (ctx == NULL)
		return ;
	if (ctx->image != NULL)
		mlx_destroy_image(ctx->mlx, ctx->image);
	if (ctx->window != NULL)
		mlx_destroy_window(ctx->mlx, ctx->window);
	if (ctx->mlx != NULL)
	{
		mlx_destroy_display(ctx->mlx);
		free(ctx->mlx);
	}
	rt_scene_destroy(&ctx->scene);
}
