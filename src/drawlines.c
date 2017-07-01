/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:42:35 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/30 19:03:34 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_points(t_env *env)
{
	void		*mlx;
	void		*win;
	int			y;
	int			x;

	y = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, env->w_wid, env->w_len, "FDF Wireframe");
	//while (y < env->len)
	//{
		x = 0;
		//while (x < env->width)
		//{
		mlx_pixel_put(mlx, win, 450, 250, env->color);
		//	x++;
	//	}
		//y++;
//	}
	mlx_loop(mlx);
}
