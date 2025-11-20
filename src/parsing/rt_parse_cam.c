/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_cam.c                                      :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:28:02 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/20 08:39:00 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int rt_parse_cam(char *line, t_la_complete *la_complete)
{
	char	**arg;

	arg = ft_split(line, ' ');
	if (!arg)
		return (ERROR_SYSTEM);
	if (rt_parse_vector(arg[1], la_complet->obj.cam.origin) ||
		rt_parse_vector(arg[2], ls_complet->obj.cam.direction))
		return (1);
	la_complete->obj.cam.fov = rt_parse_atod(arg[3]);
	return (0);
}

