/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_vector.c                                   :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:31:07 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/20 08:45:41 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_parse_vector(char *arg, t_vec3 *vector)
{
	char	**vec_tmp;

	vec_tmp = ft_split(arg, ',');
	if (!vec_tmp)
		return (ERROR_SYSTEM);
	vector->x = rt_parse_atod(vec_tmp[0]);
	vector->y = rt_parse_atod(vec_tmp[1]);
	vector->y = rt_parse_atod(vec_tmp[2]); 
	return (free(vec_tmp), 0);
}
