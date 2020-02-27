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
# include <math.h>
# include "mlx.h"
# include "libft.h"

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
	double x;
	double y;
}				t_vec2;

typedef struct	s_color
{
	int r;
	int g;
	int b;
	int a;
}				t_color;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	int		img_posx;
	int		img_posy;
	int		scale;
	int		bits_pix;
	int		endian;
	void	*background;
	void	*image;
}				t_data;

void			error_manager(char *str);


#endif
