/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math_cam_calculation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:25:03 by simon2314         #+#    #+#             */
/*   Updated: 2026/02/10 15:39:24 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "rt_math.h"

static t_vec3	center_pixel_get(t_vec3 origin, t_vec3 direction);
static t_vec3	first_pixel_get(t_vec3 center, t_cam cam);

void	rt_math_cam_calculation(t_cam *cam)
{
	t_vec3			center;
	t_vec3			world_up;
	double			dot_up;

	cam->direction = rt_math_utils_vec_normalize(cam->direction);
	world_up = (t_vec3){0, 1, 0, 0};
	dot_up = fabs(rt_math_utils_vec_dot(cam->direction, world_up));
	if (dot_up > 0.999)
	{
		world_up = (t_vec3){0, 0, 1, 0};
		dot_up = fabs(rt_math_utils_vec_dot(cam->direction, world_up));
		if (dot_up > 0.999)
			world_up = (t_vec3){1, 0, 0, 0};
	}
	cam->right = rt_math_utils_vec_cross(world_up, cam->direction);
	cam->right = rt_math_utils_vec_normalize(cam->right);
	cam->up = rt_math_utils_vec_cross(cam->direction, cam->right);
	cam->height = 2 * tan(cam->fov / 2);
	cam->width = cam->height * SIZE_X / SIZE_Y;
	center = center_pixel_get(cam->origin, cam->direction);
	cam->first_pixel = first_pixel_get(center, *cam);
}

static t_vec3	center_pixel_get(t_vec3 origin, t_vec3 direction)
{
	t_vec3	center;

	center.x = origin.x + direction.x;
	center.y = origin.y + direction.y;
	center.z = origin.z + direction.z;
	return (center);
}

static t_vec3	first_pixel_get(t_vec3 center, t_cam cam)
{
	t_vec3	first;

	first.x = center.x - cam.right.x * cam.width / 2
		+ cam.up.x * cam.height / 2;
	first.y = center.y - cam.right.y * cam.width / 2
		+ cam.up.y * cam.height / 2;
	first.z = center.z - cam.right.z * cam.width / 2
		+ cam.up.z * cam.height / 2;
	return (first);
}
