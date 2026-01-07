/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_shape_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:49:38 by simon2314         #+#    #+#             */
/*   Updated: 2026/01/07 16:51:13 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_parse_util_shape_free(t_la_complete *la_complete)
{
	t_list	*current;
	t_list	*tmp;

	current = la_complete->shape;
	while (current)
	{
		free(current->content);
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
