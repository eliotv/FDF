/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:40:22 by evanheum          #+#    #+#             */
/*   Updated: 2017/07/06 10:10:43 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libftmega.h"
# include "../libmlx/mlx.h"
# include <sys/stat.h>
# include <sys/fcntl.h>
# include <math.h>

typedef struct		s_mx
{
	float			delta;
	float			tmpx;
	float			tmpy;
	float			range;
	float			x1;
	float			y1;
	float			x;
	float			y;
	float			m;
}					t_mx;

typedef struct		s_points
{
	float				x;
	float				y;
	float				z;

}					t_points;

typedef struct		s_env
{
	int				width;
	int				len;
	int				**d2_plane;
	int				w_wid;
	int				w_len;
	float			run;
	float			rise;
	float			offset;
	float			adjust;
	float			threshold;
	int				color;
	int				y_c;
	int				x_c;
	void			*mlx;
	void			*win;
	float			ry;
	float			rz;
	float			rx;
	t_points		**points;
	t_mx			*mx;
}					t_env;
/*
** ------------- fdf.c -------------
*/
t_env				*init_env(void);
t_mx				*init_mx(void);
void				store_points(t_env *env);
/*
** ---------- drawlines.c ----------
*/
void				draw_all(t_env *env);
void				init_draw_right(t_env *env, int j, int k);
void				init_draw_down(t_env *env, int j, int k);
void				draw_else(t_env *env);
/*
** --------- drawslopes.c ----------
*/
void				draw_right(t_env *env);
void				draw_down(t_env *env);
void				draw_sharp(t_env *env);
void				draw_gradual(t_env *env);
void				draw_straight(t_env *env);
/*
** ---------- cord_plane.c ---------
*/
void				d2_num_plane(t_env *env, int fd);
void				convert_points(t_env *env, char *line, int y);
void				xy_slope(t_env *env);
void				xy_alg(t_env *env, int j, int k);
#endif
