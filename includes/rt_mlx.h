/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsurian42 <jsurian@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:56:19 by jsurian42         #+#    #+#             */
/*   Updated: 2026/02/03 12:42:12 by jsurian42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MLX_H
# define RT_MLX_H

# define SIZE_X 1600
# define SIZE_Y 1000

# define TITLE "miniRT" 

# define KEY_Q			113
# define KEY_ESC		65307
# define KEY_J 			106
# define KEY_K			107
# define KEY_D			100
# define KEY_A			97
# define KEY_W			119
# define KEY_S			115
# define ARROW_UP		65362
# define ARROW_DOWN		65364
# define LITTLECROSS	17

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

int		rt_mlx_hook(t_la_complete *self);
int		rt_mlx_hook_key(int keycode, t_la_complete *self);

#endif
