/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_light.c                                    :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:29:13 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 11:27:15 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/** 
 * @brief	parse a light line and fill la_complete->obj.light
 			light's parametres : ratio, color 
 * @return	0 on success, ERROR_SYSTEM or ... 
*/

int rt_parse_light(char *line, t_la_complete *la_complete)
{
	(void)line;
	(void)la_complete;
	return (0);
}
