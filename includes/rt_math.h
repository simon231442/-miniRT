/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:41:24 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/05 16:38:09 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

typedef struct	s_ray
{
	t_vec3	dir;
	t_vec3	origin;
}	t_ray;

int		*rt_math_pixel_get_addr(t_mlx *mlx, int x, int y);
t_vec3	rt_math_pixel_get_vec(int x, int y, double fov);
double	rt_math_sphere_get_delta(double radius, t_vec3 d, t_vec3 oc);

t_vec3	rt_math_utils_vec_normalize(t_vec3 v);
double	rt_math_utils_vec_length(t_vec3 v);
double	rt_math_utils_vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3	rt_math_utils_vec_sub(t_vec3 v1, t_vec3 v2);

int rt_math_sphere_intersect(t_ray r, t_shape *sphere, double *t);

//double	rt_math_utils_vec_dot(t_vec3 v1, t_vec3 v2);


#endif
