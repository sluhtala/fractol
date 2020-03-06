#include "fractol.h"

void	renderer(t_data *data)
{
	if (data->opt.draw_fractal)
	{	
		draw_fractal(data);	
	}
	draw_coord_grid(data, data->grid_buf);
	if (data->opt.bg)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->background, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->fractal, 0, 0);
	if (data->opt.grid)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->image, 0, 0);
	}
}
