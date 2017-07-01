/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:30:54 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/30 20:47:42 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->width = 0;
	env->len = 0;
	env->w_wid = 1000;
	env->w_len = 1000;
	env->x_scale = 0;
	env->y_scale = 0;
	env->y1 = 0;
	env->y = 0;
	env->x1 = 0;
	env->x = 0;
	env->d_x = 0;
	env->d_y = 0;
	env->x_c = 0;
	env->y_c = 0;
	env->color = 0x00FFFFFF;
	env->d2_plane = 0;
	env->points = NULL;
	env->argv_1 = NULL;
	return (env);
}

void			ft_makepoints(t_env *env)
{
	t_points	**points;
	int			y;
	int			x;

	y = 0;
	points = (t_points**)malloc(sizeof(t_points**) * env->len);
		while (y < env->len)
	{
		points[y] = (t_points*)malloc(sizeof(t_points*) * env->width);
		x = 0;
		while (x < env->width)
		{
			points[y][x].x = env->x1 + (x * (env->x_c / env->width));
			points[y][x].y = env->y1 + (y * (env->y_c / env->len));
			points[y][x].z = env->d2_plane[y][x];
			printf("[%3f][%3f][%3f]\n", points[y][x].x, points[y][x].y, points[y][x].z);
			x++;
		}
		y++;
	}
	//printf("[%3f][%3f][%3f]\n", points[0][0].x, points[0][0].y, points[0][0].z);
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
	ft_makepoints(env);
//	draw_points(env);
	return (0);
}
