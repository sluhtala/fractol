#include "fractol.h"

static int		close_program(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	exit(0);
	return (0);
}

static int	move_leftright(int key, t_data *data, double amount)
{
	int i;

	i = 0;
	if (key == LEFT_KEY)
	{
		if (data->grid_position.x > 0 && data->opt.show_grid == 1)
			data->grid_position.x -= amount;
		else if (data->grid_position.x <= 0 || data->opt.show_grid == 0)
		{
			data->frac_pos.x -= (amount * 4 / data->win_width / data->scale);
			i = 1;
		}
	}
	if (key == RIGHT_KEY)
	{
		if (data->grid_position.x < data->win_width && data->opt.show_grid == 1)
			data->grid_position.x += amount;
		else if (data->grid_position.x >= data->win_width || data->opt.show_grid == 0)
		{
			data->frac_pos.x += (amount * 4 / data->win_width / data->scale);
			i = 1;
		}
	}
	return (i);
}

static void move_updown(int key, t_data *data, double amount, int f)
{
	if (key == UP_KEY)
	{
		if (data->grid_position.y > 0 && data->opt.show_grid == 1)
			data->grid_position.y -= amount;
		else if (data->grid_position.y <= 0 || data->opt.show_grid == 0)
		{
			data->frac_pos.y -= (amount * 2 / data->win_height / data->scale);
			f = 1;
		}
	}
	if (key == DOWN_KEY)
	{
		if (data->grid_position.y < data->win_height && data->opt.show_grid == 1)
			data->grid_position.y += amount;
		else if (data->grid_position.y >= data->win_height || data->opt.show_grid == 0)
		{
			data->frac_pos.y += (amount * 2 / data->win_height / data->scale);
			f = 1;
		}
	}
	if (key == LEFT_KEY || key == RIGHT_KEY)
		f = move_leftright(key, data, amount);
	renderer(data, f);
}

static void	scale(int key, t_data *data)
{
	
		data->frac_pos.x += (data->grid_position.x * 4 / data->win_width - 2) / data->scale ;
		data->frac_pos.y += (data->grid_position.y * 2 / data->win_height - 1) / data->scale;
		data->grid_position.x = data->win_width / 2;
		data->grid_position.y = data->win_height / 2;
		if (key == 18 && data->scale > 0.6)
		{
			data->scale *= 0.8;
		}
		if (key == 19)
		{
			data->scale *= 1.2;
		}
}

int		input_manager(int key, t_data *data)
{
	if (key == ESC_KEY || key == 12)
		close_program(data);
	if (key == UP_KEY || key == DOWN_KEY ||
	key == RIGHT_KEY || key == LEFT_KEY)
		move_updown(key, data, 20, 0);
	if (key == 5 || key == 8 || key == 18 || key == 19 || key == 43 || key == 47 || key == SPACE_KEY)
	{
		if (key == 5)
		{
			if (data->opt.show_grid == 0)
				data->opt.show_grid = 1;
			else	
				data->opt.show_grid = 0;
			data->grid_position.x = data->win_width / 2;
			data->grid_position.y = data->win_height / 2;
		}
		if (key == 18 || key == 19)
			scale(key, data);
		if (key == 43 && data->max_iteration - 20 > 0)
			data->max_iteration -= 20;
		if (key == 47)
			data->max_iteration += 20;
		if (key == SPACE_KEY)
		{
			data->max_iteration = 60;
			data->scale = 90000000;
			data->frac_pos.x = 0.252534;
			data->frac_pos.y = 0;
		}
		if (key == 8) // c - center / reset
		{
			data->max_iteration = 60;
			data->grid_position.x = data->win_width / 2;
			data->grid_position.y = data->win_height / 2;
			data->frac_pos.x =  data->grid_position.x * 4 / data->win_width - 2;
			data->frac_pos.y = data->grid_position.y * 2 / data->win_height  - 1;
			data->scale = 1;
		}
		renderer(data, 1);
	}
	return (key);
}
