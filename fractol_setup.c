/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:38:15 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/12 15:38:29 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *d)
{
	*d = init_mlx("Mandelbrot");
	d->type = 0;
	draw_mandelbrot(d);
	start_fractal(d);
}

void	julia(t_data *d, long double a, long double b)
{
	*d = init_mlx("Julia");
	d->type = 1;
	d->julia_cx = a;
	d->julia_cy = b;
	draw_julia(d, a, b);
	start_fractal(d);
}

void	burningship(t_data *d)
{
	*d = init_mlx("Burning Ship");
	d->type = 2;
	draw_burningship(d);
	start_fractal(d);
}
