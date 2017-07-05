/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:42:35 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/04 18:08:32 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_all(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w_wid, env->w_len, "FDF Wireframe");
	draw_down(env);
	draw_right(env);
	mlx_loop(env->mlx);
}


void		init_draw_var(t_env *env, int j, int k)
{
	env->x = round(env->points[j][k].x);
	env->x1 = round(env->points[j][k + 1].x);
	env->y = round(env->points[j][k].y);
	env->y1 = round(env->points[j][k + 1].y);
	env->run = env->x1 - env->x;
	env->rise = env->y1 - env->y;
}
