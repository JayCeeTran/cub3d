#include "cub3d.h"

int	main(int ac, char** av)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "cub3d");
	if(validate_args(ac, av))
		return(1);
	mlx_loop(mlx);
	void *test = win;
	(void)test;
	return(0);
}
