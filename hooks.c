/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:39:44 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/14 09:36:08 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse(int button, int x, int y, t_data *d)
{
	long double	cx;
	long double	cy;

	cx = (x - WIDTH / 2.0) * 4.0 / (WIDTH * d->zoom) + d->offset_x;
	cy = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * d->zoom) + d->offset_y;
	if (button == MOUSE_SCROLL_UP)
		d->zoom *= 1.2;
	if (button == MOUSE_SCROLL_DOWN)
		d->zoom /= 1.2;
	d->offset_x = cx - (x - WIDTH / 2.0) * 4.0 / (WIDTH * d->zoom);
	d->offset_y = cy - (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * d->zoom);
	mlx_clear_window(d->mlx, d->win);
	if (d->type == 0)
		draw_mandelbrot(d);
	else if (d->type == 1)
		draw_julia(d, d->julia_cx, d->julia_cy);
	else if (d->type == 2)
		draw_burningship(d);
	return (0);
}

int	handle_key(int keycode, t_data *d)
{
	long double	move_step;

	move_step = 0.2 / d->zoom;
	if (keycode == KEY_ESC)
		ft_close(d);
	else if (keycode == KEY_UP)
		d->offset_y -= move_step;
	else if (keycode == KEY_DOWN)
		d->offset_y += move_step;
	else if (keycode == KEY_LEFT)
		d->offset_x -= move_step;
	else if (keycode == KEY_RIGHT)
		d->offset_x += move_step;
	else if (keycode == KEY_C)
		d->color_offset += 0.05;
	else
		return (0);
	mlx_clear_window(d->mlx, d->win);
	if (d->type == 0)
		draw_mandelbrot(d);
	else if (d->type == 1)
		draw_julia(d, d->julia_cx, d->julia_cy);
	else if (d->type == 2)
		draw_burningship(d);
	return (0);
}

int	ft_close(t_data *d)
{
	if (d->img)
		mlx_destroy_image(d->mlx, d->img);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
	}
	exit(0);
	return (0);
}
