/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:14:19 by sluhtala          #+#    #+#             */
/*   Updated: 2020/03/09 19:28:21 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

t_vec2		inverse_transform(t_vec2 xy, t_data *data, double x, double y)
{
	xy.x = (long double)x * 4 / (long double)data->win_width - 2;
	xy.y = (long double)y * 2 / (long double)data->win_height - 1;
	xy.x /= data->scale;
	xy.y /= data->scale;
	return (xy);
}

static void	print_stats(t_data *data)
{
	ft_printf("\nthreads: %d\n", THREADS);
	ft_printf("max_iter: %d\n", data->max_iteration);
	ft_printf("zoom_lvl: %Lf\n", data->scale);
	ft_printf("frac_p_x: %.10Lf\n", data->frac_pos.x);
	ft_printf("frac_p_y: %.10Lf\n", -data->frac_pos.y);
}

/*
**	In order to proof that it is using multiple threads a fuction
**	'printf("%p\n", pthread_self())' can be called. It will give
**	the thread id and it should show that there are different ids
**	for different threads.
*/

void		loop_threads(t_data *data)
{
	t_color	col;
	int		i;
	t_xy	xy;

	i = data->i;
	pthread_mutex_unlock(&data->lock);
	xy.y = 0 + i * data->win_height / THREADS;
	while (xy.y < (i + 1) * data->win_height / THREADS)
	{
		xy.x = 0;
		while (xy.x < data->win_width)
		{
			if (data->frac_num == 1 || data->frac_num == 0)
				col = draw_mandelbrot(data, xy.x, xy.y);
			if (data->frac_num == 2)
				col = draw_julia(data, xy.x, xy.y);
			if (data->frac_num == 3)
				col = draw_burning_ship(data, xy.x, xy.y);
			set_image_pixel_color(data, data->fractal_buf, xy.x + xy.y *
					data->win_width, col);
			xy.x++;
		}
		xy.y++;
	}
}

void		draw_fractal(t_data *data)
{
	t_color col;
	int		i;

	print_stats(data);
	if (data->opt.bg)
	{
		col.a = 255;
		fill_image(data, data->win_width * data->win_height * 4,
			data->fractal_buf, col);
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
