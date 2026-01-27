/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_vector.c                              :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:31:07 by srenaud           #+#    #+#             */
/*   Updated: 2025/12/01 12:56:25 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	vector_is_valid(char **vector);

int	rt_parse_util_vector(char *arg, t_vec3 *vector)
{
	char	**vec_tmp;

	vec_tmp = ft_split(arg, ',');
	if (!vec_tmp)
		return (rt_error_put(ERROR_SYSTEM), 1);
	if (!vector_is_valid(vec_tmp))
	{
		//return (1);
	}
	vector->x = rt_parse_util_atod(vec_tmp[0]);
	vector->y = rt_parse_util_atod(vec_tmp[1]);
	vector->y = rt_parse_util_atod(vec_tmp[2]); 
	return (free(vec_tmp), 0);
}

static int	vector_is_valid(char **vector)
{
	if (ft_arg_count(vector) != 3)
		return (rt_error_put(ERROR_VECTOR), 0);
	while (*vector)
	{
		if (!ft_real_format_is_valid(*vector))
			return (rt_error_put(ERROR_REAL_NB_FORMAT), 0);
		if (!ft_real_is_in_range(*vector,"-2147483648", "2147483647"))
		{
			printf("aille vector_is_pas_valid %s\n", *vector);
			//return (rt_error_put(ERROR_OUT_OF_RANGE), 0);
		}
		printf("vector %s\n is valid", *vector);
		vector++;
	}
	return (1);
}
