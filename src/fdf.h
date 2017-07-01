/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evanheum <evanheum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:40:22 by evanheum          #+#    #+#             */
/*   Updated: 2017/06/30 19:13:32 by evanheum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/megalibft.h"
# include "../minilibx_macos/mlx.h"
# include <sys/stat.h>
# include <sys/fcntl.h>
# include <stdio.h>

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
	int				**d2_nodes;
	int				w_wid;
	int				w_len;
	int				x1;
	int				y1;
	int				x;
	int				y;
	int				d_x;
	int				d_y;
	int				color;
	int				x_scale;
	int				y_scale;
	int				y_c;
	int				x_c;
	char			*argv_1;
	t_points		**points;
}					t_env;
/*
** ------------- fdf.c -------------
*/
t_env				*init_env(void);
void				printstring(t_env *env);
void				ft_makepoints(t_env *env);
/*
** ---------- drawlines.c ----------
*/
void				draw_points(t_env *env);
/*
** ---------- cord_plane.c ---------
*/
void				d2_num_plane(t_env *env, int fd);
void				plot_points(t_env *env, char *line, int y);
#endif
