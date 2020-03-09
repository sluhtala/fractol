/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:58:45 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 18:17:07 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"

static void		mlx_initialize(t_data *data)
{
	int w;
	int h;

	w = data->win_width;
	h = data->win_height;
	if (!(data->mlx_win = mlx_new_window(data->mlx_ptr, w, h, "Fractol")))
		error_manager("Error opening window.");
	data->image = mlx_new_image(data->mlx_ptr, w, h);
	data->fractal = mlx_new_image(data->mlx_ptr, w, h);
	data->grid_buf = mlx_get_data_addr(data->image, &data->bits_pix,
		&data->size_line, &data->endian);
	data->fractal_buf = mlx_get_data_addr(data->fractal, &data->bits_pix,
		&data->size_line, &data->endian);
}

static t_data	initialize(t_data *data)
{
	data->opt.help = 0;
	data->mouse.down = 0;
	data->opt.screen_lock = 0;
	if (data->frac_num == 2)
		data->opt.screen_lock = 1;
	data->opt.palette = 1;
	data->opt.draw_fractal = 1;
	data->opt.grid = 0;
	data->opt.bg = 1;
	data->mlx_ptr = mlx_init();
	data->win_width = WINWIDTH;
	data->win_height = WINHEIGHT;
	data->img_posx = 0;
	data->img_posy = 0;
	data->grid_position.x = WINWIDTH / 2;
	data->grid_position.y = WINHEIGHT / 2;
	data->scale = 1.0;
	data->frac_pos.x = data->grid_position.x * 4 / data->win_width - 2;
	data->frac_pos.y = data->grid_position.y * 2 / data->win_height - 1;
	data->max_iteration = 60;
	mlx_initialize(data);
	return (*data);
}

static int		read_parameter(char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0 || ft_strcmp(str, "1") == 0)
		return (1);
	if (ft_strcmp(str, "julia") == 0 || ft_strcmp(str, "2") == 0)
		return (2);
	if (ft_strcmp(str, "burningship") == 0 || ft_strcmp(str, "3") == 0)
		return (3);
	return (0);
}

int				main(int argc, char **argv)
{
	t_data data;

	if (argc > 2)
	{
		ft_printf("Usage: ./fractol <fractal-name>\n");
		ft_printf("Available fractals: 'mandelbrot' 'julia' 'burningship'\n");
		return (0);
	}
	if (argc == 2)
		data.frac_num = read_parameter(argv[1]);
	if (data.frac_num == 2)
		data.opt.screen_lock = 1;
	data = initialize(&data);
	create_background(&data);
	draw_coord_grid(&data, data.grid_buf);
	renderer(&data);
	mlx_hook(data.mlx_win, 6, 0, &mouse_track, &data);
	mlx_mouse_hook(data.mlx_win, &mouse_manager, &data);
	mlx_hook(data.mlx_win, 5, 0, &mouse_release, &data);
	mlx_hook(data.mlx_win, 2, 0, &input_manager, &data);
	mlx_hook(data.mlx_win, 17, 0, &close_program, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
