/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:39:31 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/12 15:39:34 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

# define MANDELBROT 0
# define JULIA 1
# define BURNING_SHIP 2

typedef struct s_complex
{
	long double	re;
	long double	im;
}				t_complex;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits;
	int			line;
	int			endian;
	long double	zoom;
	long double	offset_x;
	long double	offset_y;
	int			type;
	long double	julia_cx;
	long double	julia_cy;
	long double	color_offset;
}				t_data;

t_data			init_mlx(char *title);
void			my_mlx_pixel_put(t_data *d, int x, int y, int color);
void			start_fractal(t_data *d);
void			mandelbrot(t_data *d);
void			julia(t_data *d, long double a, long double b);
void			burningship(t_data *d);

void			draw_mandelbrot(t_data *d);
void			draw_julia(t_data *d, long double cx, long double cy);
void			draw_burningship(t_data *d);
int				get_color(int i, int limit, long double color_offset);

int				get_iter_limit(t_data *d);
int				compute_mandelbrot(t_complex c, t_data *d);
int				compute_julia(t_complex z, t_complex c, t_data *d);
int				compute_burningship(t_complex c, t_data *d);

long double		complex_magnitude_sq(t_complex z);
t_complex		complex_square(t_complex z);

int				handle_mouse(int button, int x, int y, t_data *d);
int				handle_key(int keycode, t_data *d);
int				ft_close(t_data *d);

#endif