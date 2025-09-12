/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:33:39 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/12 15:38:10 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int i, int limit, long double color_offset)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == limit)
		return (0x000000);
	t = fmod((double)i / limit + color_offset, 1.0);
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

int	get_iter_limit(t_data *d)
{
	int	limit;

	limit = MAX_ITER + (int)(20 * log(d->zoom));
	if (limit < MAX_ITER)
		limit = MAX_ITER;
	return (limit);
}

void	draw_mandelbrot(t_data *d)
{
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * d->zoom) + d->offset_x;
			c.im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * d->zoom) + d->offset_y;
			my_mlx_pixel_put(d, x, y, get_color(compute_mandelbrot(c, d),
					get_iter_limit(d), d->color_offset));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	draw_julia(t_data *d, long double cx, long double cy)
{
	int			x;
	int			y;
	t_complex	z;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			z.re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * d->zoom) + d->offset_x;
			z.im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * d->zoom) + d->offset_y;
			c.re = cx;
			c.im = cy;
			my_mlx_pixel_put(d, x, y, get_color(compute_julia(z, c, d),
					get_iter_limit(d), d->color_offset));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

void	draw_burningship(t_data *d)
{
	int			x;
	int			y;
	t_complex	c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * d->zoom) + d->offset_x;
			c.im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * d->zoom) + d->offset_y;
			my_mlx_pixel_put(d, x, y, get_color(compute_burningship(c, d),
					get_iter_limit(d), d->color_offset));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}
