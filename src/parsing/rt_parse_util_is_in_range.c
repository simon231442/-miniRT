/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_is_in_range.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:13:09 by simon2314         #+#    #+#             */
/*   Updated: 2025/12/29 15:13:09 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_higher(char *value, char *limit);

int	rt_parse_util_is_in_range(char *value, char *min, char *max)
{
	// min 4 value 5 max 6
	if (!is_higher(min, value) && is_higher(max, value))
		return (1);


	int	value_len;
	int	min_len;
	int	max_len;

	value_len = ft_strlen(value);
	min_len = ft_strlen(min);
	max_len = ft_strlen(max);
	//val 2351 < min 235 && val 235 < max 2351
	if (value_len < max_len)
		return
	if (value_len > min_len	&& value_len < max_len)
		return (1);
	if (value_len > min_len	|| value_len > max_len)
		return (0);
	if (is_higher(value, max))
		return (0);
	if (is_higher(min, value))
		return (1);
	return (0);
}

int	is_higher(char *value, char *limit)
{
	if (*value == '-' && *limit == '-')
	{
		limit++;
		value++;
	}
	else if (*value != '-' && *limit == '-')
		return (1);
	else if (*value == '-' && *limit != '-')
		return (0);
	while (*value && *limit)
	{
		if (*limit == '.' && *value && *value != '.')
			return (1);
		if (*value == '.' && *limit && *limit != '.')
			return (0);
		if (*value > *limit)
			return (1);
		value++;
		if (*value == '\0')
			return (0);
		limit++;
	}
	return (1);
}

