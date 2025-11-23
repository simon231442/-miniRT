/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error_put.c                                      :+:    :+:           */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@42lausanne.ch>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:41:28 by srenaud           #+#    #+#             */
/*   Updated: 2025/11/21 16:04:37 by srenaud        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rt_error_put(char *message)
{
	ft_putendl_fd("Error\n", 2);
	ft_putendl_fd(message, 2);
}
