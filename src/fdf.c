/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:30:54 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/04 16:28:50 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->width = 0;
	env->len = 0;
	env->w_wid = 1920;
	env->w_len = 1080;
	env->y1 = 0;
	env->y = 0;
	env->x1 = 0;
	env->x = 0;
	env->run = 0;
	env->tmpy = 0;
	env->tmpx = 0;
	env->delta = 0;
	env->range = 0;
	env->rise = 0;
	env->x_c = 0;
	env->y_c = 0;
	env->color = 0x00FFFFFF;
	env->mlx = NULL;
	env->win = NULL;
	env->d2_plane = 0;
	env->rx = 0.785398;
    env->ry = 0;
    env->rz = 0.615472907;
	env->m = 0;
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
			env->points[j][k].x = env->x1 + (k * (env->x_c / env->width));
			env->points[j][k].y = j * (env->y_c / env->len);
			env->points[j][k].z = env->d2_plane[j][k];
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
