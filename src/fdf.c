/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:30:54 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/06 10:20:41 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mx			*init_mx(void)
{
	t_mx		*mx;

	mx = (t_mx*)malloc(sizeof(t_mx));
	mx->m = 0;
	mx->y1 = 0;
	mx->y = 0;
	mx->x1 = 0;
	mx->x = 0;
	mx->tmpy = 0;
	mx->tmpx = 0;
	mx->delta = 0;
	mx->range = 0;
	return (mx);
}

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->mx = init_mx();
	env->width = 0;
	env->len = 0;
	env->w_wid = 1920;
	env->w_len = 1080;
	env->run = 0;
	env->rise = 0;
	env->color = 0xFFFFFF;
	env->mlx = NULL;
	env->win = NULL;
	env->d2_plane = 0;
	env->rx = 0.785398;
	env->ry = 0;
	env->rz = 0.615472907;
	env->adjust = 0;
	env->threshold = 0;
	env->offset = 0;
	return (env);
}

void			store_points(t_env *env)
{
	int			j;
	int			k;

	j = 0;
	env->points = (t_points**)malloc(sizeof(t_points*) * env->len);
	while (j < env->len)
	{
		k = 0;
		env->points[j] = (t_points*)malloc(sizeof(t_points) * env->width);
		while (k < env->width)
		{
			env->points[j][k].x = env->mx->x1 + (k * (700 / env->width));
			env->points[j][k].y = (j * (700 / env->width));
			env->points[j][k].z = 5 * env->d2_plane[j][k];
			k++;
		}
		j++;
	}
}

int				main(int ac, char **av)
{
	t_env		*env;
	int			fd;

	if (ac != 2)
	{
		ft_printf("\033[31mINVALID NUMBER OF ARGUMENTS\n\033[0m");
		return (0);
	}
	env = init_env();
	fd = open(av[1], O_RDONLY);
	d2_num_plane(env, fd);
	store_points(env);
	xy_slope(env);
	draw_all(env);
	return (0);
}
