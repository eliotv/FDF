/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawslopes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:39:52 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/06 10:10:00 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_straight(t_env *env)
{
	float tmp;

	tmp = 0;
	if (env->mx->y1 < env->mx->y)
	{
		tmp = env->mx->y;
		env->mx->y = env->mx->y1;
		env->mx->y1 = tmp;
	}
	while (env->mx->y <= env->mx->y1)
	{
		mlx_pixel_put(env->mlx, env->win, env->mx->x, env->mx->y, env->color);
		env->mx->y++;
	}
}

void	draw_gradual(t_env *env)
{
	env->mx->delta = fabsf(env->mx->m);
	env->mx->tmpy = env->mx->y;
	if (env->mx->x1 < env->mx->x)
	{
		env->mx->tmpx = env->mx->x;
		env->mx->x = env->mx->x1;
		env->mx->x1 = env->mx->tmpx;
		env->mx->tmpy = env->mx->y1;
	}
	env->mx->range = (env->mx->x1 - env->mx->x);
	while (env->mx->x < env->mx->x1)
	{
		mlx_pixel_put(env->mlx, env->win, env->mx->x, env->mx->tmpy,
			env->color);
		env->offset += env->mx->delta;
		if (env->offset >= env->threshold)
		{
			env->mx->tmpy += env->adjust;
			env->threshold += 1;
		}
		env->mx->x++;
	}
}

void	draw_sharp(t_env *env)
{
	env->mx->delta = fabsf(env->run / env->rise);
	env->mx->tmpx = env->mx->x;
	if (env->mx->y1 < env->mx->y)
	{
		env->mx->tmpy = env->mx->y;
		env->mx->y = env->mx->y1;
		env->mx->y1 = env->mx->tmpy;
		env->mx->tmpx = env->mx->x1;
	}
	env->mx->range = (env->mx->y1 - env->mx->y);
	while (env->mx->y < env->mx->y1)
	{
		mlx_pixel_put(env->mlx, env->win, env->mx->tmpx, env->mx->y,
			env->color);
		env->offset += env->mx->delta;
		if (env->offset >= env->threshold)
		{
			env->mx->tmpx += env->adjust;
			env->threshold += 1;
		}
		env->mx->y++;
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
		while (k < env->width)
		{
			init_draw_down(env, j, k);
			if (env->run == 0 && j + 1 < env->len)
				draw_straight(env);
			else
				draw_else(env);
			k++;
		}
		j++;
	}
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
			init_draw_right(env, j, k);
			if (env->run == 0 && k + 1 < env->len)
				draw_straight(env);
			else
				draw_else(env);
			k++;
		}
		j++;
	}
}
