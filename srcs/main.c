/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:58:45 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/04 14:40:07 by sluhtala         ###   ########.fr       */
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
	data->opt.grid = 1;
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
	data->win_width, data->win_height, "FDF")))
		error_manager("Error opening window.");
	data->image = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->fractal = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	data->grid_buf = mlx_get_data_addr(data->image, &data->bits_pix, &data->size_line, &data->endian);
	data->fractal_buf = mlx_get_data_addr(data->fractal, &data->bits_pix, &data->size_line, &data->endian);
	return (*data);
}


int				main(void)
{
	t_data data;

	data = initialize(&data);
	create_background(&data);
	draw_coord_grid(&data, data.grid_buf);
	renderer(&data, 1);
	mlx_hook(data.mlx_win, 2, 0, &input_manager, &data);
	mlx_hook(data.mlx_win, 17, 0, &close_program, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
