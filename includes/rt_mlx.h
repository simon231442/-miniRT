/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:56:19 by jsurian42         #+#    #+#             */
/*   Updated: 2026/01/15 16:33:39 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

# define SIZE_X 1600
# define SIZE_Y 1600

# define TITLE "miniRT" 

# define KEY_Q 113

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_addr;
	int		img_bpp;
	int		img_line;
	int		img_endian;
}	t_mlx;

int		rt_mlx_init(t_mlx *self);
void	rt_mlx_free(t_mlx *self);

int		rt_mlx_hook(t_mlx *self);
int		rt_mlx_hook_key(int keycode, t_mlx *self);

#endif
