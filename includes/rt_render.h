/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:14:10 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/10 15:49:58 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_RENDER_H
# define RT_RENDER_H

# define SPHERE		0
# define PLANE		1
# define CYLINDER	2

# include "rt_math.h"

typedef struct s_render_view
{
	int		x;
	int		y;
	int		*pixel_addr;
	t_vec3	pixel_vec;
}	t_render_view;

typedef struct s_pixel_view
{
	t_ray	r;
	double	t_min;
	t_shape	*last_shape;
	double	intensity;
	t_color	color;
	t_list	*shape_list;
}	t_pixel_view;

typedef struct s_light_view
{
	t_vec3	intersect_point;
	t_vec3	normal_vec;
	double	cosinus_angle;
	double	intensity;
	t_ray	light_ray;
	double	light_distance;
}	t_light_view;

int		rt_render(t_la_complete *la_complete);
int		*rt_render_pixel_get_addr(t_mlx *mlx, int x, int y);
int		rt_render_pixel_get_color(t_list *shape, t_obj obj, t_render_view v);

int		rt_render_shape_intersect(t_list *shape_lst, t_shape **last_shape,
			t_ray r, double *t_min);

int		rt_render_choose_shape_intersect(t_ray r, t_shape *shape, double *t);

double	rt_render_light_get_intensity(t_pixel_view *p, t_obj obj);
int		rt_render_shadow_intersect(t_list *shape_lst, t_shape **last_shape,
			t_ray r, double light_distance);

t_color	rt_render_pixel_get_ret_color(t_color shape_color, t_ambient ambient,
			double intensity);

#endif
