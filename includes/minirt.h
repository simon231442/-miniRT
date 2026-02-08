/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:20:49 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/03 12:30:22 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>


# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec3;


typedef struct s_color
{
	double r;
	double g;
	double b;
}	t_color;

typedef struct s_cam
{
	t_vec3	origin;
	t_vec3	direction;
	double	fov;
	double	height;
	double	width;
	t_vec3	first_pixel;
	t_vec3	right;
	t_vec3	up;
}	t_cam;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	t_vec3	origin;
	double	ratio;
	t_color	color;
}	t_light;

typedef enum e_shape_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_shape_type;

typedef enum e_hit_type
{
	BODY,
	TOP,
	BOTTOM
}	t_hit_type;

typedef struct s_shape
{
	t_shape_type	type;
	t_vec3			origin;
	double			radius;
	double			height;
	t_vec3			direction;
	t_color			color;
	t_hit_type		hit_type;
}	t_shape;

typedef struct s_obj
{
	t_cam		cam;
	t_ambient	ambient;
	t_light		light;
}	t_obj;

typedef struct	s_la_complete	t_la_complete;

# include "rt_mlx.h"

typedef struct s_la_complete
{
	t_mlx	mlx;
	t_obj	obj;
	t_list	*shape;
	int		error_status;
}	t_la_complete;

# include "rt_parsing.h"
# include "rt_error.h"
# include "rt_math.h"
# include "rt_render.h"

# include "rt_debug.h"

#endif
