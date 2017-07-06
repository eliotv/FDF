/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:42:35 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/05 15:24:09 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_all(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w_wid, env->w_len, "FDF Wireframe");
	draw_right(env);
	draw_down(env);
	mlx_loop(env->mlx);
}


void		init_draw_right(t_env *env, int j, int k)
{
	if (k + 1 < env->width)
	{
		env->x = round(env->points[j][k].x);
		env->x1 = round(env->points[j][k + 1].x);
		env->y = round(env->points[j][k].y);
		env->y1 = round(env->points[j][k + 1].y);
		env->run = env->x1 - env->x;
		env->rise = env->y1 - env->y;
	}
}

void		init_draw_down(t_env *env, int j, int k)
{
	if (j + 1 < env->len)
	{
		env->x = round(env->points[j][k].x);
		env->x1 = round(env->points[j + 1][k].x);
		env->y = round(env->points[j][k].y);
		env->y1 = round(env->points[j + 1][k].y);
		env->run = env->x1 - env->x;
		env->rise = env->y1 - env->y;
	}
}
