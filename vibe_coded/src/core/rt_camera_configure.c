/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_camera_configure.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "rt_camera.h"
#include "rt_math.h"
#include "rt_error.h"

int	rt_camera_configure(t_camera *camera)
{
	t_vec3	world_up;
	double	alignment;

	if (camera == NULL)
		return (rt_error("Camera missing"));
	if (rt_math_vec3_length(camera->orientation) < RT_EPSILON)
		return (rt_error("Camera orientation invalid"));
	camera->orientation = rt_math_vec3_normalize(camera->orientation);
	world_up = rt_math_vec3(0.0, 1.0, 0.0);
	alignment = fabs(rt_math_vec3_dot(camera->orientation, world_up));
	if (alignment > 0.999)
		world_up = rt_math_vec3(1.0, 0.0, 0.0);
	camera->right = rt_math_vec3_normalize(
		rt_math_vec3_cross(camera->orientation, world_up));
	camera->up = rt_math_vec3_normalize(
		rt_math_vec3_cross(camera->right, camera->orientation));
	return (0);
}
