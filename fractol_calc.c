/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:31:44 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/12 15:33:09 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	complex_magnitude_sq(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

t_complex	complex_square(t_complex z)
{
	t_complex	result;

	result.re = z.re * z.re - z.im * z.im;
	result.im = 2 * z.re * z.im;
	return (result);
}

int	compute_mandelbrot(t_complex c, t_data *d)
{
	t_complex	z;
	int			i;
	int			limit;

	limit = get_iter_limit(d);
	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (complex_magnitude_sq(z) < 4 && i < limit)
	{
		z = complex_square(z);
		z.re += c.re;
		z.im += c.im;
		i++;
	}
	return (i);
}

int	compute_julia(t_complex z, t_complex c, t_data *d)
{
	int	i;
	int	limit;

	limit = get_iter_limit(d);
	i = 0;
	while (complex_magnitude_sq(z) < 4 && i < limit)
	{
		z = complex_square(z);
		z.re += c.re;
		z.im += c.im;
		i++;
	}
	return (i);
}

// Nova função para o fractal Burning Ship.
int	compute_burningship(t_complex c, t_data *d)
{
	t_complex	z;
	t_complex	z_tmp;
	int			i;
	int			limit;

	limit = get_iter_limit(d);
	z.re = 0.0;
	z.im = 0.0;
	i = 0;
	while (complex_magnitude_sq(z) < 4 && i < limit)
	{
		z_tmp.re = fabsl(z.re);
		z_tmp.im = fabsl(z.im);
		z = complex_square(z_tmp);
		z.re += c.re;
		z.im += c.im;
		i++;
	}
	return (i);
}
