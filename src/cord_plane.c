/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 11:53:44 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/05 20:48:41 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		xy_slope(t_env *env)
{
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			xy_alg(env, j ,k);
			k++;
		}
		j++;
	}
}
void 	xy_alg(t_env *env, int j, int k)
{
	float x;

	x = env->points[j][k].x  * (cos(env->ry) * cos(env->rz))
	- env->points[j][k].y * (cos(env->ry) * cos(env->rz))
	+ env->points[j][k].z * sin(env->ry);
	env->points[j][k].y = env->points[j][k].x * (sin(env->rx) * sin(env->ry)
	* cos(env->rz) + cos(env->rx) * sin(env->rz))+ env->points[j][k].y
	* (sin(env->rz) * sin(env->rx) * sin(env->ry) + cos(env->rx) * cos(env->rz))
	- env->points[j][k].z * cos(env->ry) * sin(env->rx);
	env->points[j][k].x = x;
}

void		convert_points(t_env *env, char *line, int y)
{
	int		x;
	char **string;

	x = 0;
	env->d2_plane[y] = (int*)malloc(sizeof(int) * env->width);
	while (x < env->width)
	{
		string = ft_strsplit(line, ' ');
		env->d2_plane[y][x] = ft_atoi(string[x]);
		x++;
	}
	printf("\n");
}

void		d2_num_plane(t_env *env, int fd)
{
	char	**line;//stores the input file
	int		y; //count of the lines read from the input file //length from the starting to ending points

	y = 0;
	line = (char**)malloc(sizeof(char*) * UINT_MAX);
	while (get_next_line(fd, &line[env->len]))
		env->len++;

	env->width = ft_count_wrd(*line, ' ');
	env->x_c= env->w_wid / 2;
	env->y_c = env->w_len / 2;
	env->x1 = env->x_c;
	env->d2_plane = (int**)malloc(sizeof(int*) * env->len);
	while (y < env->len)
	{
		convert_points(env, line[y], y);
		y++;
	}
}
