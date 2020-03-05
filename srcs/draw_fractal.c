/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:14:19 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/05 19:53:14 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>
#include <stdio.h>

static t_vec2 inverse_transform(t_vec2 xy, t_data *data, double x, double y)
{
	xy.x = (long double)x * 4 / (long double)data->win_width  - 2;
	xy.y = (long double)y * 2 / (long double)data->win_height - 1;
	xy.x /= data->scale; 
	xy.y /= data->scale;
	return (xy);
}

static t_color set_frac_color(t_data *data, t_color col, double angle,
	int i, t_vec2 ab)
{
	int iter;
	double d;
	
	iter = data->max_iteration;
	col = hsv(360 * i / data->max_iteration, 0.7,  1, i * i / iter * iter);;
	if (ab.x < 2.0 && ab.y <= 2.0)
	{
		col = hsv(230, 0, 1,0);
	}
	return (col);
}

static t_color	draw_mandelbrot(t_data *data, char *buf, int x, int y)
{
	int i;
	t_vec2 xy;
	t_vec2 ab[2];
	long double xtemp;
	double angle;

	xy = inverse_transform(xy, data, x, y);
	xy.x += data->frac_pos.x;
	xy.y += data->frac_pos.y;
	ab[0].x = 0;
	ab[0].y = 0;
	i = 0;
	angle = 0;
	while (ab[0].x <= 2 && ab[0].y <= 2 && i++ < data->max_iteration)
	{
		xtemp = ab[0].x * ab[0].x - ab[0].y * ab[0].y + xy.x;
		ab[0].y = 2.0 * ab[0].x * ab[0].y + xy.y;
		ab[0].x = xtemp;
		angle = atan2(ab[1].x - ab[0].x, ab[1].y - ab[0].y) * 180 / M_PI;
		ab[1].x = ab[0].x;
		ab[1].y = ab[0].y;	
	}
	return (set_frac_color(data, color_init(data, 0), angle, i, ab[0]));
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
	while (y < (i + 1) * data->win_height / THREADS)
	{
		x = 0;
		while (x < data->win_width)
		{
			col = draw_mandelbrot(data, data->fractal_buf, x, y);
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
	col = color_init(data, 0);
	//col.a = 255;
	//image_size = data->win_width * data->win_height;
	//fill_image(data, image_size * 4, data->fractal_buf, col);
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
