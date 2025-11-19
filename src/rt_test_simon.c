/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_test_simon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon2314 <simon2314@42lausanne.ch>        #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 18:22:52 by simon2314         #+#    #+#             */
/*   Updated: 2025/11/15 18:22:52 by simon2314        ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	int		i;
	double	number;

	i = 1;
	while (i < ac)
	{
		number = rt_atod(av[i]);
		printf("%f\n",number);
		i++;
	}
}