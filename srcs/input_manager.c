#include "fractol.h"

int		close_program(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	ft_putstr("Good bye.\n");
	exit(0);
	return (0);
}

/*
**	Esc and q closes the program
**	Arrow keys to move around or move the grid
**	G to toggel grid-mode
**	C to center or reset the position and scale
**	, . to change the maximum iteration
**	1 2 to zoom out and zoom in
*/

static void	input_action_manager(int key, t_data *data)
{
	if (key == UP_KEY || key == DOWN_KEY ||
	key == RIGHT_KEY || key == LEFT_KEY)
		move_updown(key, data, 20, 0);
	if (key == 8)
	{
		data->max_iteration = 60;
		data->grid_position.x = data->win_width / 2;
		data->grid_position.y = data->win_height / 2;
		data->frac_pos.x =  data->grid_position.x * 4 / data->win_width - 2;
		data->frac_pos.y = data->grid_position.y * 2 / data->win_height  - 1;
		data->scale = 1;
	}
	if (key == 5)
	{
		if (data->opt.grid == 0)
			data->opt.grid = 1;
		else	
			data->opt.grid = 0;
		data->grid_position.x = data->win_width / 2;
		data->grid_position.y = data->win_height / 2;
	}
}

int		mouse_manager(int button, int x, int y,  t_data *data)
{
	data->mouse.pos_x = x;
	data->mouse.pos_y = y;	
	if (button == 4 || button == 5)
	{
		ft_putnbr(button);
		scale(button, data);
		renderer(data);
	}
	return (0);
}

int		input_manager(int key, t_data *data)
{
	if (key == ESC_KEY || key == 12)
		close_program(data);
	if (key == UP_KEY || key == DOWN_KEY ||
	key == RIGHT_KEY || key == LEFT_KEY)
		input_action_manager(key, data);
	if (key == 5 || key == 8 || key == 18 || key == 19
			|| key == 43 || key == 47 || key == SPACE_KEY)
	{
		if (key == 18 || key == 19)
		{
			scale(key, data);
		}
		if (key == 43 && data->max_iteration - 20 > 0)
			data->max_iteration -= 20;
		if (key == 47)
			data->max_iteration += 20;
		if (key == 8 || key == 5)
			input_action_manager(key, data);
		if (key == SPACE_KEY)
		{
			ft_putstr("Hello World\n");
		}
		data->opt.draw_fractal = 1;
		renderer(data);
	}
	return (key);
}
