#include "Libmlx/mlx.h"
#include <stdio.h>

typedef struct	s_env
{
	void		*mlx
	void		*win;
}				t_env;

int		my_key_funct(int keycode, t_env *env)
{
	printf("keycode event %d\n", keycode);
	if (keycode == 53)
		return (1);
	return (0);
}

int	main(void)
{
	t_env	env;
	int		y;
	int		x;
	int		color;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1000, 1000, "FDF 42");
	y = 500;
	color = 0x00FFFFFF;
	while (y < 750)
	{
		x = 500;
		while (x < 750)
		{
			mlx_pixel_put(env.mlx, env.win, x, y, color);
			x++;
		}
		y++;
	}
//	mlx_key_hook(win, my_key_funct, &env);
	mlx_loop(env.mlx);
}
