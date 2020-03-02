#include "fractol.h"

void	renderer(t_data *data, int f)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	//if (f)
	//	draw_fractal(data, data->fractal_buf);
	draw_coord_grid(data, data->grid_buf);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->background, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->fractal, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->image, 0, 0);
}
