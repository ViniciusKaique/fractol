/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 09:34:42 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/14 11:34:03 by vinpache         ###   ########.fr       */
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
		z = (t_complex){
			complex_square(z).re + c.re,
			complex_square(z).im + c.im};
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
		z = (t_complex){
			complex_square(z).re + c.re,
			complex_square(z).im + c.im};
		i++;
	}
	return (i);
}

int	compute_burningship(t_complex c, t_data *d)
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
		z = (t_complex){
			complex_square((t_complex){fabsl(z.re), fabsl(z.im)}).re + c.re,
			complex_square((t_complex){fabsl(z.re), fabsl(z.im)}).im + c.im};
		i++;
	}
	return (i);
}
