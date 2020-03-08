/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:14:19 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/06 17:47:13 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <stdio.h>

t_vec2 inverse_transform(t_vec2 xy, t_data *data, double x, double y)
{
	xy.x = (long double)x * 4 / (long double)data->win_width - 2;
	xy.y = (long double)y * 2 / (long double)data->win_height - 1;
	xy.x /= data->scale; 
	xy.y /= data->scale;
	return (xy);
}

t_color set_frac_color(t_data *data, t_color col, double angle,
	int i, t_vec2 ab)
{
	int iter;
	double d;

	if (data->opt.palette > 5)
		data->opt.palette = 1;	
	iter = data->max_iteration;
	if (data->opt.palette == 1)
	{
		if (i >= iter)
			col = hsv(230, 0, 1,0);
		else
			col = hsv(360 * i / data->max_iteration, 0.7,  1, 0);
	}
	if (data->opt.palette == 2)
	{
		if (i >= iter)
			col = hsv(230, 0, 1,0);
		else
			col = hsv(360 - 360 * i / data->max_iteration, 0.3,  1, 0);	
	}
	if (data->opt.palette == 3)
	{
		if (i >= iter)
			col = hsv(130, 0.4, 1,0);
		else
			col = hsv(angle, 1,  1, i /  iter);;
	}
	if (data->opt.palette == 4)
	{
		if (i >= iter)
			col = hsv(360 *  data->opt.palette * i / iter, 1, 1, 0);
		else
			col.a = 255;;
	}
	if (data->opt.palette == 5)
	{
		if (i >= iter)
			col = hsv(360 , 1, 0, 0);
		else
			col.a = 255;;
	}
	return (col);
}


static void print_stats(t_data *data)
{
	printf("\nthreads: %d\n", THREADS);
	printf("max_iter: %d\n", data->max_iteration);
	printf("zoom_lvl: %Lf\n", data->scale);
	printf("frac_p_x: %Lf\n", data->frac_pos.x);
	printf("frac_p_y: %Lf\n", data->frac_pos.y);
}

/*
**
**
**	In order to proof that it is using multiple threads a fuction
**	'printf("%p\n", pthread_self())' can be called. It will give
**	the thread id and it should show that there are different ids
**	for different threads.
**
**
**
*/

void	loop_threads(t_data *data)
{
	t_color col;
	int offset;
	int i;
	int y;
	int x;

	i = data->i;
	pthread_mutex_unlock(&data->lock);
	y = 0 + i * data->win_height / THREADS;
	col = color_init(data, 0);
	while (y < (i + 1) * data->win_height / THREADS)
	{
		x = 0;
		while (x < data->win_width)
		{
			if (data->frac_num == 1 || data->frac_num == 0)
				col = draw_mandelbrot(data, data->fractal_buf, x, y);
			if (data->frac_num == 2)
				col = draw_julia(data, data->fractal_buf, x, y);
			if (data->frac_num == 3)
				col = draw_burning_ship(data, data->fractal_buf, x, y);
			set_image_pixel_color(data, data->fractal_buf, x + y * data->win_width, col);
			x++;
		}	
		y++;
	}
	
}

void	draw_fractal(t_data *data)
{
	t_color col;
	int image_size;
	int i;

	print_stats(data);
	if (data->opt.bg)
	{
		col.a = 255;
		image_size = data->win_width * data->win_height;
		fill_image(data, image_size * 4, data->fractal_buf, col);
	}
	data->i = 0;
	i = 0;
	if ((pthread_mutex_init(&data->lock, NULL) == -1))
			error_manager("Mutex error.");
	while (i < THREADS)
	{
		pthread_mutex_lock(&data->lock);	
		data->i = i;
		pthread_create(&data->threadid[i], NULL, (void*)loop_threads, data);
		i++;
	}
	i = 0;
	while (i++ < THREADS)
		pthread_join(data->threadid[i - 1], NULL);
	pthread_mutex_destroy(&data->lock);
}
