/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: github <github@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:00:00 by github            #+#    #+#             */
/*   Updated: 2025/11/03 00:00:00 by github           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCTS_H
# define RT_STRUCTS_H

# include <stddef.h>

# define RT_IMAGE_WIDTH 800
# define RT_IMAGE_HEIGHT 600
# define RT_MAX_SHAPES 128

typedef struct s_vec3
{
	double		x;
	double		y;
	double		z;
}	t_vec3;

typedef struct s_color
{
	double		r;
	double		g;
	double		b;
}	t_color;

typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		direction;
}	t_ray;

typedef struct s_camera
{
	t_vec3		position;
	t_vec3		orientation;
	t_vec3		right;
	t_vec3		up;
	double		fov;
}	t_camera;

typedef struct s_ambient
{
	double		ratio;
	t_color		color;
}	t_ambient;

typedef struct s_light
{
	t_vec3		position;
	double		brightness;
	t_color		color;
}	t_light;

typedef enum e_shape_type
{
	RT_SHAPE_SPHERE,
	RT_SHAPE_PLANE,
	RT_SHAPE_CYLINDER
}	t_shape_type;

typedef struct s_sphere
{
	t_vec3		center;
	double		radius;
	t_color		color;
}	t_sphere;

typedef struct s_plane
{
	t_vec3		point;
	t_vec3		normal;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3		center;
	t_vec3		axis;
	double		radius;
	double		height;
	t_color		color;
}	t_cylinder;

typedef union u_shape_data
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_shape_data;

typedef struct s_shape
{
	t_shape_type	type;
	t_shape_data	data;
}	t_shape;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_shape		shapes[RT_MAX_SHAPES];
	size_t		shape_count;
}	t_scene;

typedef struct s_hit
{
	int		hit;
	double		distance;
	t_vec3		point;
	t_vec3		normal;
	t_color		color;
}	t_hit;

typedef struct s_context
{
	void		*mlx;
	void		*window;
	void		*image;
	char		*buffer;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
	t_scene		scene;
}	t_context;

#endif
