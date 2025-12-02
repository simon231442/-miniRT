/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_debug_scene_obj_display.c                        :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:12:12 by srenaud           #+#    #+#             */
/*   Updated: 2025/12/01 16:49:38 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	obj_display(t_shape *shape);
static void	sphere_display(t_shape *shape);
static void	plane_display(t_shape *shape);
static void	cylinder_display(t_shape *shape);

void	rt_debug_scene_obj_display(t_la_complete *la_complete)
{
	t_list	*current;
	int		i;

	current = la_complete->shape;
	if (!current)
	{
		printf("No objects in the scene.\n");
		return ;
	}
	i = 0;
	while (current)
	{
		printf("Object %d:\n", i);
		obj_display((t_shape *)current->content);
		current = current->next;
		i++;
	}
}

static void	obj_display(t_shape *shape)
{
	if (shape->type == SPHERE)
		sphere_display(shape);
	else if (shape->type == PLANE)
		plane_display(shape);
	else if (shape->type == CYLINDER)
		cylinder_display(shape);
}

static void	sphere_display(t_shape *shape)
{
	printf("Sphere display\n");
	printf("--------------------------\n");
	printf("Origin: (%.2f, %.2f, %.2f)\n",
		shape->origin.x,
		shape->origin.y,
		shape->origin.z);
	printf("Radius: %.2f\n", shape->radius);
	printf("Color: (%.2f, %.2f, %.2f)\n",
		shape->color.r,
		shape->color.g,
		shape->color.b);
	printf("--------------------------\n\n");
	return ;
}

static void	plane_display(t_shape *shape)
{
	printf("Plane display\n");
	printf("--------------------------\n");
	printf("Origin: (%.2f, %.2f, %.2f)\n",
		shape->origin.x,
		shape->origin.y,
		shape->origin.z);
	printf("Direction: (%.2f, %.2f, %.2f)\n",
		shape->direction.x,
		shape->direction.y,
		shape->direction.z);
	printf("Color: (%.2f, %.2f, %.2f)\n",
		shape->color.r,
		shape->color.g,
		shape->color.b);
	printf("--------------------------\n\n");
	return ;
}

static void	cylinder_display(t_shape *shape)
{
	printf("Cylinder display\n");
	printf("--------------------------\n");
	printf("Origin: (%.2f, %.2f, %.2f)\n",
		shape->origin.x,
		shape->origin.y,
		shape->origin.z);
	printf("Direction: (%.2f, %.2f, %.2f)\n",
		shape->direction.x,
		shape->direction.y,
		shape->direction.z);
	printf("Radius: %.2f\n", shape->radius);
	printf("Height: %.2f\n", shape->height);
	printf("Color: (%.2f, %.2f, %.2f)\n",
		shape->color.r,
		shape->color.g,
		shape->color.b);
	printf("--------------------------\n\n");
	return ;
}
