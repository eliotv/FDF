/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:42:35 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/06 10:10:47 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_all(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w_wid, env->w_len,
		"FDF Wireframe");
	draw_right(env);
	draw_down(env);
	mlx_loop(env->mlx);
}

void		init_draw_right(t_env *env, int j, int k)
{
	if (k + 1 < env->width)
	{
		env->mx->x = round(env->points[j][k].x);
		env->mx->x1 = round(env->points[j][k + 1].x);
		env->mx->y = round(env->points[j][k].y);
		env->mx->y1 = round(env->points[j][k + 1].y);
		env->run = env->mx->x1 - env->mx->x;
		env->rise = env->mx->y1 - env->mx->y;
	}
}

void		init_draw_down(t_env *env, int j, int k)
{
	if (j + 1 < env->len)
	{
		env->mx->x = round(env->points[j][k].x);
		env->mx->x1 = round(env->points[j + 1][k].x);
		env->mx->y = round(env->points[j][k].y);
		env->mx->y1 = round(env->points[j + 1][k].y);
		env->run = env->mx->x1 - env->mx->x;
		env->rise = env->mx->y1 - env->mx->y;
	}
}

void		draw_else(t_env *env)
{
	env->mx->m = env->rise / env->run;
	env->adjust = env->mx->m >= 0 ? 1 : -1;
	env->offset = 0;
	env->threshold = 0.5;
	if (env->mx->m <= 1 && env->mx->m >= -1)
		draw_gradual(env);
	else
		draw_sharp(env);
}
