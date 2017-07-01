/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 11:53:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/30 20:44:09 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		plot_points(t_env *env, char *line, int y)
{
	int		x;

	x = 0;
	env->d2_plane[y] = (int*)malloc(sizeof(int*) * env->len);
	while (x < env->width)
	{

		env->d2_plane[y][x] = ft_atoi(line);
		while (*line >= '0' && *line <= '9')
			line++;
		while (*line == ' ')
			line++;
		if (*line < '0' && *line > '9')
		{
			ft_printf("\033[31mINVALID FILE!\n\033[0m");
			return ;
		}
		x++;
	}
}

void		d2_num_plane(t_env *env, int fd)
{/*
**.
*/
	char	**line;//stores the input file
	int		y; //count of the lines read from the input file //length from the starting to ending points
	//int		center;// takes w_wid and w_len finds the center of those dimensions center = 0,0.

	y = 0;
	line = (char**)malloc(sizeof(char**) * UINT_MAX);
	while (get_next_line(fd, &line[y]))
		y++;

	env->len = y;
	env->width = ft_count_wrd(*line, ' ');
	env->x_c= env->w_wid / 2;
	env->y_c = env->w_len / 2;
	env->y1 = env->y_c / 2; //* (env->len / 10);
	env->x1 = env->x_c / 2; //* (env->width / 10);
	env->d2_plane = (int**)malloc(sizeof(int**) * env->len);
	env->x_scale = env->w_wid / env->width;
	env->y_scale = env->w_len / env->len;
	y = 0;
	//printf("len = %d\n width = %d", env->x_scale, env->y_scale);
	//printf("")
	while (y < env->len)
	{
		plot_points(env, line[y], y);
		y++;
	}
}
