/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 11:53:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/04 11:23:37 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		xy_slope(t_env *env)
{
	int j;
	int k;
	float x;

	j = 0;
	x = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			x = env->points[j][k].x  * (cos(env->ry) * cos(env->rz))
			- env->points[j][k].y * (cos(env->ry) * cos(env->rz))
			+ env->points[j][k].z * sin(env->ry);
			env->points[j][k].y = env->points[j][k].x * (sin(env->rx) * sin(env->ry) * cos(env->rz) + cos(env->rx) * sin(env->rz))
			+ env->points[j][k].y * (sin(env->rz) * sin(env->rx) * sin(env->ry) + cos(env->rx) * cos(env->rz))
			- env->points[j][k].z * cos(env->ry) * sin(env->rx);
			env->points[j][k].x = x;
			// printf ("[%3f][%3f]\n", env->points[j][k].x, env->points[j][k].y);
			k++;
		}
		j++;
	}
}
void		plot_points(t_env *env, char *line, int y)
{
	int		x;

	x = 0;
	env->d2_plane[y] = (int*)malloc(sizeof(int) * env->width);
	while (x < env->width)
	{

		while (*line == ' ')
			line++;
		while (*line != ' ' && *line != '\0')
		{
			env->d2_plane[y][x] = ft_atoi(line);
			line++;
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

	y = 0;
	line = (char**)malloc(sizeof(char*) * UINT_MAX);
	while (get_next_line(fd, &line[y]))
		y++;

	env->len = y;
	env->width = ft_count_wrd(*line, ' ');
	env->x_c= env->w_wid / 2;
	env->y_c = env->w_len / 2;
	// env->y1 =env->y_c / env->w_wid;
	env->x1 = env->x_c;
	// printf("[%3d]\n", env->y1);
	env->d2_plane = (int**)malloc(sizeof(int*) * env->len);
	// env->x_scale = env->w_wid / env->width;
	// env->y_scale = env->w_len / env->len;
	y = 0;
	while (y < env->len)
	{
		plot_points(env, line[y], y);
		y++;
	}
}
