#include "fractol.h"

static void	select_screen(t_data *data)
{
	int xpos;

	xpos = 0;
	data->opt.screen_lock = 1;
	data->mouse.track_x = 0;
	data->mouse.track_y = data->win_height / 4;
	data->frac_pos.x = 0;
	data->frac_pos.y = 0;
	data->scale = 1;
	data->max_iteration = 60;
	while (xpos < data->win_width - 1)
	{
		data->frac_pos.x = (xpos) * 4 / data->win_width;
		data->frac_num++;
		draw_fractal(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->background, xpos, 0);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->fractal, xpos, 0);
		xpos += data->win_width / 3;
	}
	data->frac_num = 0;
	data->opt.screen_lock = 0;
	data->frac_pos.x = 0;
}

void	renderer(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	if (data->frac_num == 0)
	{
		select_screen(data);
		return ;
	}
	if (data->opt.draw_fractal)
	{	
		draw_fractal(data);	
	}
	draw_coord_grid(data, data->grid_buf);
	if (data->opt.bg)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->background, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->fractal, 0, 0);
	if (data->opt.grid)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->image, 0, 0);
}
