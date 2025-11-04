/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

# include "rt_structs.h"

# define RT_EPSILON 1e-6

t_vec3	rt_math_vec3(double x, double y, double z);
t_vec3	rt_math_vec3_add(t_vec3 a, t_vec3 b);
t_vec3	rt_math_vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	rt_math_vec3_scale(t_vec3 v, double s);
double	rt_math_vec3_dot(t_vec3 a, t_vec3 b);
t_vec3	rt_math_vec3_cross(t_vec3 a, t_vec3 b);
double	rt_math_vec3_length(t_vec3 v);
t_vec3	rt_math_vec3_normalize(t_vec3 v);

double	rt_math_clamp(double value, double min, double max);

#endif
