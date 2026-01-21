/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:41:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/21 15:07:38 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

typedef struct	s_ray
{
	t_vec3	dir;
	t_vec3	origin;
}	t_ray;

typedef	struct	s_intersect_view
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	sqrt_delta;
	double	t0;
	double	t1;
}	t_intersect_view;

t_vec3	rt_math_pixel_get_vec(int x, int y, double fov, t_vec3 direction);
//double	rt_math_sphere_get_delta(double radius, t_vec3 d, t_vec3 oc);

t_vec3	rt_math_utils_vec_normalize(t_vec3 v);
double	rt_math_utils_vec_length(t_vec3 v);
double	rt_math_utils_vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3	rt_math_utils_vec_sub(t_vec3 v1, t_vec3 v2);
t_vec3	rt_math_utils_vec_cross(t_vec3 v1, t_vec3 v2);
t_vec3	rt_math_utils_vec_add(t_vec3 v1, t_vec3 v2);
t_vec3	rt_math_utils_vec_multi_scale(t_vec3 v, double scalar);

int	rt_math_shape_intersect(t_ray r, t_shape shape, double *t);
int rt_math_sphere_intersect(t_ray r, t_shape sphere, double *t);
int	rt_math_plane_intersect(t_ray r, t_shape plane, double *t);

t_vec3	rt_math_shape_get_normal(t_vec3 intersect_point, t_shape *shape);
t_vec3	rt_math_sphere_get_normal(t_vec3 intersect_point, t_vec3 origin_sphere);
t_vec3	rt_math_cylinder_get_normal();

t_vec3	rt_math_get_intersect_point(t_ray r, double t_min);

t_vec3	rt_math_light_get_vec(t_vec3 intersect_point, t_vec3 light_origin);
double	rt_math_utils_get_cosinus(t_vec3 normal_vec, t_vec3 light_vec);


#endif
