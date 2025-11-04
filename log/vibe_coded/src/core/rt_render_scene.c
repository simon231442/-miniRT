/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rt_render.h"
#include "rt_camera.h"
#include "rt_color.h"
#include "rt_intersect.h"
#include "rt_math.h"

#include "rt_error.h"

typedef struct s_render_config
{
	double	aspect;
	double	scale;
	int		bytes_per_pixel;
}t_render_config;

typedef struct s_render_light
{
	t_vec3	direction;
	double	distance;
	t_color	diffuse;
	t_ray	shadow_ray;
	t_hit	shadow_hit;
	double	dot;
}t_render_light;

typedef struct s_render_pixel
{
	t_ray	ray;
	t_hit	hit;
	t_color	color;
	int		packed;
	int		offset;
}t_render_pixel;

static int	rt_render_setup(t_context *ctx, t_render_config *config)
{
	double	fov_radians;

	if (rt_camera_configure(&ctx->scene.camera) != 0)
		return (1);
	if (ctx->scene.camera.fov <= 0.0 || ctx->scene.camera.fov >= 180.0)
		return (rt_error("Camera FOV invalid"));
	fov_radians = ctx->scene.camera.fov * M_PI / 180.0;
	config->aspect = (double)RT_IMAGE_WIDTH / (double)RT_IMAGE_HEIGHT;
	config->scale = tan(fov_radians * 0.5);
	config->bytes_per_pixel = ctx->bits_per_pixel / 8;
	if (config->bytes_per_pixel <= 0)
		return (rt_error("Invalid image format"));
	return (0);
}

static t_ray	rt_render_make_ray(const t_context *ctx,
			const t_render_config *config, int x, int y)
{
	t_ray	ray;
	t_vec3	direction;
	double	pixel_u;
	double	pixel_v;

	ray.origin = ctx->scene.camera.position;
	pixel_u = (2.0 * ((x + 0.5) / (double)RT_IMAGE_WIDTH) - 1.0)
		* config->scale;
	pixel_v = (1.0 - 2.0 * ((y + 0.5) / (double)RT_IMAGE_HEIGHT))
		* (config->scale / config->aspect);
	direction = rt_math_vec3_add(ctx->scene.camera.orientation,
		rt_math_vec3_add(rt_math_vec3_scale(ctx->scene.camera.right, pixel_u),
			rt_math_vec3_scale(ctx->scene.camera.up, pixel_v)));
	ray.direction = rt_math_vec3_normalize(direction);
	return (ray);
}

static t_color	rt_render_lighting(t_context *ctx, t_hit *hit, t_ray ray)
{
	t_render_light	light;
	t_color			ambient;

	(void)ray;
	ambient = rt_color_scale(rt_color_mul(hit->color, ctx->scene.ambient.color),
		ctx->scene.ambient.ratio);
	light.direction = rt_math_vec3_sub(ctx->scene.light.position, hit->point);
	light.distance = rt_math_vec3_length(light.direction);
	if (light.distance < RT_EPSILON)
		return (rt_color_clamp(ambient, 0.0, 1.0));
	light.direction = rt_math_vec3_scale(light.direction, 1.0 / light.distance);
	light.dot = rt_math_vec3_dot(hit->normal, light.direction);
	if (light.dot > 0.0)
	{
		light.shadow_ray.origin = rt_math_vec3_add(hit->point,
			rt_math_vec3_scale(hit->normal, RT_EPSILON * 10.0));
		light.shadow_ray.direction = light.direction;
		if (rt_intersect_scene(&ctx->scene, light.shadow_ray,
				&light.shadow_hit) != 0
			&& light.shadow_hit.distance + RT_EPSILON < light.distance)
			light.dot = 0.0;
	}
	light.diffuse = rt_color(0.0, 0.0, 0.0);
	if (light.dot > 0.0)
		light.diffuse = rt_color_scale(rt_color_mul(hit->color,
			ctx->scene.light.color), ctx->scene.light.brightness * light.dot);
	return (rt_color_clamp(rt_color_add(ambient, light.diffuse), 0.0, 1.0));
}

static void	rt_render_scanline(t_context *ctx,
			const t_render_config *config, int y)
{
	t_render_pixel	pixel;
	int			x;

	x = 0;
	while (x < RT_IMAGE_WIDTH)
	{
		pixel.ray = rt_render_make_ray(ctx, config, x, y);
		if (rt_intersect_scene(&ctx->scene, pixel.ray, &pixel.hit) != 0)
			pixel.color = rt_render_lighting(ctx, &pixel.hit, pixel.ray);
		else
			pixel.color = rt_color(0.0, 0.0, 0.0);
		pixel.packed = rt_color_to_int(pixel.color);
		pixel.offset = (y * ctx->size_line) + (x * config->bytes_per_pixel);
		*(int *)(ctx->buffer + pixel.offset) = pixel.packed;
		x++;
	}
}

int	rt_render_scene(t_context *ctx)
{
	t_render_config	config;
	int			y;

	if (ctx == NULL)
		return (rt_error("Context missing"));
	if (rt_render_setup(ctx, &config) != 0)
		return (1);
	y = 0;
	while (y < RT_IMAGE_HEIGHT)
	{
		rt_render_scanline(ctx, &config, y);
		y++;
	}
	return (0);
}
