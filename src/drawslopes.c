/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawslopes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:39:52 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/04 18:15:02 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_straight(t_env *env)
{
	float tmp;

	tmp = 0;
	if (env->y1 < env->y)
	{
		tmp = env->y;
		env->y = env->y1;
		env->y1 = tmp;
	}
	while (env->y <= env->y1)
	{
		mlx_pixel_put(env->mlx, env->win, env->x, env->y, env->color);
		env->y++;
	}
}

void	draw_gradual(t_env *env)
{

	env->delta = fabsf(env->m);
	env->tmpy = env->y;
	if (env->x1 < env->x)
	{
		env->tmpx = env->x;
		env->x = env->x1;
		env->x1 = env->tmpx;
		env->tmpy = env->y1;
	}
	env->range = (env->x1 - env->x);
	while (env->x  < env->x1)
	{
		mlx_pixel_put(env->mlx, env->win, env->x, env->tmpy, env->color);
		env->offset += env->delta;
		if (env->offset >= env->threshold)
		{
			env->tmpy += env->adjust;
			env->threshold += 1;
		}
		env->x++;
	}
}

void	draw_sharp(t_env *env)
{
	env->delta = fabsf(env->run /env->rise);
	env->tmpx = env->x;
	if (env->y1 < env->y)
	{
		env->tmpy = env->y;
		env->y = env->y1;
		env->y1 = env->tmpy;
		env->tmpx = env->x1;
	}
	env->range = (env->y1 - env->y);
	while (env->y < env->y1)
	{
		mlx_pixel_put(env->mlx, env->win, env->tmpx, env->y, env->color);
		env->offset += env->delta;
		if (env->offset >= env->threshold)
		{
			env->tmpx += env->adjust;
			env->threshold += 1;
		}
		env->y++;
	}
}

void	draw_down(t_env *env)
{
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while ( k < env->width)
		{
			init_draw_var(env, j, k);
			if (env->run == 0 && j + 1 < env->len)
				draw_straight(env);
			else
			{
				env->m = env->rise / env->run;
				env->adjust = env->m >= 0 ? 1: -1;
				env->offset = 0;
				env->threshold = 0.5;
				if (env->m <= 1 && env->m >= -1)
					draw_gradual(env);
				else
					draw_sharp(env);
			}
		}
		k++;
	}
	j++;
}

void	draw_right(t_env *env)
{
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			init_draw_var(env, j, k);
			if (env->run == 0 && k + 1 < env->len)
				draw_straight(env);
			else
			{
				env->m = env->rise / env->run;
				env->adjust = env->m >= 0 ? 1 : -1;
				env->offset = 0;
				env->threshold = 0.5;
				if (env->m <= 1 && env->m >= -1)
					draw_gradual(env);
				else
					draw_sharp(env);
			}
		}
		k++;
	}
	j++;
}
