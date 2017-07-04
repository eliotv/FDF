/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:42:35 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/04 13:02:10 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_all(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->w_wid, env->w_len, "FDF Wireframe");
	place_points(env);
	// draw_horz(env);
	// draw_vert(env);
	mlx_loop(env->mlx);
}

void		place_points(t_env *env)
{
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			mlx_pixel_put(env->mlx, env->win, env->points[j][k].x, env->points[j][k].y, env->color);
			k++;
		}
		j++;
	}
//	printf("%f\n", env->points[0][0].x);//[env->width - 1].x);
}

void		draw_horz(t_env *env)
{
	int j;
	int k;
	int tmpy;

	j = 0;
	while (j < env->len)
	{
		env->d_x = env->points[j][k + 1].x - env->points[j][k].x
		env->d_y = env->points[j][k + 1].y - env->points[j][k].y
		env->D = 2 * env->d_y - env->d_x;
		tmpy = env->points[j][k].y
		while ()
		{
			mlx_pixel_put(env->mlx, env->win, env->points[j][k].x, env->points[j][k].y, env->color);
			if (env->D > 0)
			{
				tmpy += 1;
				env->D -= (2 * env->d_y);
			}
			D += (2 * env->d_y);

		}


	}
}

void		draw_vert(t_env *env)
{
	int j;
	int k;

	j = 0;
	while (j < env->width)
	{
		k = env->points[0][1].y;
		// printf("%d\n", k);
		while(k < env->points[env->len - 1][0].y)
		{
			mlx_pixel_put(env->mlx, env->win, env->points[0][j].x, k, env->color);
			k++;
		}
		j++;
	}
}
