/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:31:07 by srenaud           #+#    #+#             */
/*   Updated: 2026/01/07 15:49:14 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	rt_parse_util_vector(char *arg, t_vec3 *vector)
{
	char	**vec_tmp;

	vec_tmp = ft_split(arg, ',');
	if (!vec_tmp)
		return (rt_error_put(ERROR_SYSTEM), 1);
	vector->x = rt_parse_util_atod(vec_tmp[0]);
	vector->y = rt_parse_util_atod(vec_tmp[1]);
	vector->z = rt_parse_util_atod(vec_tmp[2]); 
	return (free(vec_tmp), 0);
}
