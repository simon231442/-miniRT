/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   rt_math_pixel_get_addr.c                           :+:      :+:    :+:   */
/*                                                      +:+                   */
/*   By: jsurian <jsurian@student.42lausanne.ch>       +#+                    */
/*                                                    +#+                     */
/*   Created: 2025/12/15 16:52:05 by jsurian        #+#    #+#                */
/*   Updated: 2026/01/05 10:07:46 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	*rt_math_pixel_get_addr(t_mlx *mlx, int x, int y)
{
	int	*addr;

	addr = mlx->img_addr + y * mlx->img_line + x * mlx->img_bpp / 8;
	return (addr);
}
