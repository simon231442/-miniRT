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

# define RT_IMAGE_WIDTH 800 /* Rendered image width in pixels */
# define RT_IMAGE_HEIGHT 600 /* Rendered image height in pixels */
# define RT_MAX_SHAPES 128 /* Maximum number of shapes stored in a scene */

typedef struct s_vec3
{
	double		x; /* X component of a 3D vector */
	double		y; /* Y component of a 3D vector */
	double		z; /* Z component of a 3D vector */
}t_vec3;

typedef struct s_color
{
	double		r; /* Red channel intensity in 0.0-1.0 */
	double		g; /* Green channel intensity in 0.0-1.0 */
	double		b; /* Blue channel intensity in 0.0-1.0 */
}t_color;

typedef struct s_ray
{
	t_vec3		origin; /* Ray starting point in world space */
	t_vec3		direction; /* Normalized direction vector of the ray */
}t_ray;

typedef struct s_camera
{
	t_vec3		position; /* Camera viewpoint location */
	t_vec3		orientation; /* Forward direction the camera looks toward */
	t_vec3		right; /* Camera horizontal basis vector */
	t_vec3		up; /* Camera vertical basis vector */
	double		fov; /* Horizontal field of view in degrees */
}t_camera;

typedef struct s_ambient
{
	double		ratio; /* Scalar multiplier applied to ambient lighting */
	t_color	color; /* Base ambient light color */
}t_ambient;

typedef struct s_light
{
	t_vec3		position; /* Point light position in world space */
	double		brightness; /* Light power factor in 0.0-1.0 */
	t_color	color; /* Light emission color */
}t_light;

typedef enum e_shape_type
{
	RT_SHAPE_SPHERE, /* Shape entry represents a sphere */
	RT_SHAPE_PLANE, /* Shape entry represents an infinite plane */
	RT_SHAPE_CYLINDER /* Shape entry represents a finite cylinder */
}t_shape_type;

typedef struct s_sphere
{
	t_vec3		center; /* Sphere center position */
	double		radius; /* Sphere radius in world units */
	t_color	color; /* Diffuse surface color of the sphere */
}t_sphere;

typedef struct s_plane
{
	t_vec3		point; /* A reference point lying on the plane */
	t_vec3		normal; /* Normalized surface normal of the plane */
	t_color	color; /* Diffuse surface color of the plane */
}t_plane;

typedef struct s_cylinder
{
	t_vec3		center; /* Center point of the cylinder body */
	t_vec3		axis; /* Normalized axis direction of the cylinder */
	double		radius; /* Cylinder radius in world units */
	double		height; /* Cylinder height along its axis */
	t_color	color; /* Diffuse surface color of the cylinder */
}t_cylinder;

typedef union u_shape_data
{
	t_sphere	sphere; /* Storage for sphere-specific attributes */
	t_plane	plane; /* Storage for plane-specific attributes */
	t_cylinder	cylinder; /* Storage for cylinder-specific attributes */
}t_shape_data;

typedef struct s_shape
{
	t_shape_type	type; /* Active type describing which shape union member to use */
	t_shape_data	data; /* Union containing parameters for the active shape */
}t_shape;

typedef struct s_scene
{
	t_ambient	ambient; /* Global ambient lighting configuration */
	t_camera	camera; /* Active camera describing view parameters */
	t_light	light; /* Primary point light used for shading */
	t_shape	shapes[RT_MAX_SHAPES]; /* Collection of scene primitives */
	size_t		shape_count; /* Number of active shapes stored in the array */
}t_scene;

typedef struct s_hit
{
	int		hit; /* Boolean flag indicating if an intersection occurred */
	double		distance; /* Distance from ray origin to intersection point */
	t_vec3		point; /* Coordinates of the intersection point */
	t_vec3		normal; /* Surface normal at the intersection point */
	t_color	color; /* Surface color sampled at the hit */
}t_hit;

typedef struct s_context
{
	void		*mlx; /* Pointer to the MiniLibX connection handle */
	void		*window; /* Pointer to the opened rendering window */
	void		*image; /* Pointer to the MLX image resource used for drawing */
	char		*buffer; /* Raw pixel buffer mapped from the MLX image */
	int			size_line; /* Number of bytes in a single image row */
	int			bits_per_pixel; /* Pixel color depth reported by MLX */
	int			endian; /* Endianness flag provided by MLX for the buffer */
	t_scene	scene; /* Entire scene data currently loaded and rendered */
}t_context;

#endif
