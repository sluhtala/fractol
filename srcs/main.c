/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:58:45 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/06 16:49:37 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include <math.h>
#include <stdio.h>


/*
**
**
**
**
*/


/*
**	- Initialize mlx
**	- Set screen dimensions
*/


static t_data initialize(t_data *data)
{
	data->opt.screen_lock = 0;
	data->frac_num = 0;
	data->opt.palette = 1;
	data->opt.draw_fractal = 1;
	data->opt.grid = 1;
	data->opt.bg = 1;
	data->mlx_ptr = mlx_init();
	data->win_width =  WINWIDTH;
	data->win_height = WINHEIGHT;
	data->img_posx = 0;
	data->img_posy = 0;
	data->grid_position.x = WINWIDTH / 2;
	data->grid_position.y = WINHEIGHT / 2;
	data->scale = 1.0;
	data->frac_pos.x = data->grid_position.x * 4 / data->win_width - 2;
	data->frac_pos.y = data->grid_position.y * 2 / data->win_height - 1;
	data->max_iteration = 60;
	if (!(data->mlx_win = mlx_new_window(data->mlx_ptr,
	data->win_width, data->win_height, "Fractol")))
		error_manager("Error opening window.");
	data->image = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->fractal = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->grid_buf = mlx_get_data_addr(data->image, &data->bits_pix, &data->size_line, &data->endian);
	data->fractal_buf = mlx_get_data_addr(data->fractal, &data->bits_pix, &data->size_line, &data->endian);
	return (*data);
}


static int	mouse_track(int x, int y, t_data *data)
{
	data->mouse.track_x = (long double)x;
	data->mouse.track_y = (long double)y;
	if (data->opt.screen_lock == 1)
	{
		data->opt.draw_fractal = 1;	
		renderer(data);
	}
	return (0);
}


int				main(int argc, char **argv)
{
	t_data data;

	if (argc > 2)
		return (0);
	data = initialize(&data);
	if (argc == 2)
		data.frac_num = ft_atoi(argv[1]);
	if (data.frac_num > 3)
		data.frac_num = 3;
	if (data.frac_num == 2)
		data.opt.screen_lock = 1;
	create_background(&data);
	draw_coord_grid(&data, data.grid_buf);
	renderer(&data);
	mlx_hook(data.mlx_win, 6, 0, &mouse_track, &data);
	mlx_mouse_hook(data.mlx_win, &mouse_manager, &data);
	mlx_hook(data.mlx_win, 2, 0, &input_manager, &data);
	mlx_hook(data.mlx_win, 17, 0, &close_program, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
