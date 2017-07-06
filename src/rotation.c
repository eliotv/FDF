/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 17:08:23 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/05 20:35:15 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rot_z(t_env *env)
{
	float y;
	float x;
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			y = env->points[j][k].y;
			x = env->points[j][k].x;
			env->points[j][k].y = (x * cos(0.7954) - y * sin(0.7954));
			env->points[j][k].x = (x * sin(0.7954) + y * cos(0.7954));
			k++;
		}
		j++;
	}
}

void		rot_y(t_env *env)
{
	float x;
	float z;
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			x = env->points[j][k].x;
			z = env->points[j][k].z;
			env->points[j][k].x = (x * cos(0.0524) + z * sin(0.0524));
			env->points[j][k].z = - (x * sin(0.0524) + z * cos(0.0524));
			k++;
		}
		j++;
	}
}

void		rot_x(t_env *env)
{
	float y;
	float z;
	int j;
	int k;

	j = 0;
	while (j < env->len)
	{
		k = 0;
		while (k < env->width)
		{
			y = env->points[j][k].y;
			z = env->points[j][k].z;
			env->points[j][k].y = (y * cos(0.6982) - z * sin(0.6982));
			env->points[j][k].z = (y * sin(0.6982) + z * cos(0.6982));
			k++;
		}
		j++;
	}
}

void		rotation(t_env *env)
{
	rot_x(env);
	rot_y(env);
	rot_z(env);
}
