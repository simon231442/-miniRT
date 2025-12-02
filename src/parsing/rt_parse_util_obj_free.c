/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_util_obj_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:49:38 by simon2314         #+#    #+#             */
/*   Updated: 2025/12/02 22:49:38 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_parse_util_obj_free(t_la_complete *la_complete)
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

