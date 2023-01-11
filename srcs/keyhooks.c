#include "../includes/cub3d.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		x_close(data);
	return (0);
}

int	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}