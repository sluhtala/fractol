/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sluhtala <sluhtala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:54:04 by sluhtala          #+#    #+#             */
/*   Updated: 2020/02/27 18:41:27 by sluhtala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ESC_KEY 53
# define UP_KEY 126
# define DOWN_KEY 125
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define SPACE_KEY 49
# define BLUE 0x0000ff
# define RED 0xff0000
# define GREEN 0x00ff00
# define GRAY 0x888888
# define DARKGRAY 0x222222
# define WHITE 0xffffff
# define WINWIDTH 1280 / 2
# define WINHEIGHT 720 / 2
# define THREADS 10
//200 = 1 min 9  sec
//500 = 1 min 7  sec
//10  = 1 min 17 sec
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <pthread.h>

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
	double	w;
	int		color;
}				t_vec3;

typedef struct	s_vec2
{
	long double x;
	long double y;
}				t_vec2;

typedef struct	s_options
{
	int show_grid;
}				t_options;

typedef struct	s_color
{
	double r;
	double g;
	double b;
	double a;
}				t_color;

typedef struct	s_data
{
	t_options	opt;
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	int		img_posx;
	int		img_posy;
	long double	scale;
	int		bits_pix;
	int		size_line;
	int		endian;
	t_vec2	grid_position;
	void	*background;
	void	*image;
	void	*fractal;
	char	*fractal_buf;
	char	*grid_buf;
	int		max_iteration;
	int 	x;
	int		y;
	int		i;
	t_vec2	frac_pos;
	pthread_mutex_t lock;
}				t_data;

void		error_manager(char *str);
t_color		color_init(t_data *data, int hex);
void		create_background(t_data *data);
void	set_image_pixel_color(t_data *data, char *img_buf, int pos, t_color col);
void	draw_vertical_line(t_data *data, char *buffer, int x, t_color col);
void	draw_horizontal_line(t_data *data, char *buffer, int y, t_color col);
void	fill_image(t_data *data, int buf_size, char *img_buf, t_color color);
int		input_manager(int key, t_data *data);
void	draw_coord_grid(t_data *data, char *buffer);
void	renderer(t_data *data, int f);
void	draw_fractal(t_data *data);
t_color	hsv(double hue, double saturation, double value, double alpha);

#endif
