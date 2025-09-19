/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:40:58 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/14 09:36:10 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_mlx(char *title)
{
	t_data	d;

	d.mlx = mlx_init();
	if (!d.mlx)
		exit(1);
	d.win = mlx_new_window(d.mlx, WIDTH, HEIGHT, title);
	d.img = mlx_new_image(d.mlx, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.bits, &d.line, &d.endian);
	d.zoom = 1.0;
	d.offset_x = 0.0;
	d.offset_y = 0.0;
	d.color_offset = 0.0;
	return (d);
}

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dest;

	dest = d->addr + (y * d->line + x * (d->bits / 8));
	*(unsigned int *)dest = color;
}

void	start_fractal(t_data *d)
{
	mlx_mouse_hook(d->win, handle_mouse, d);
	mlx_hook(d->win, 2, 1L << 0, handle_key, d);
	mlx_hook(d->win, 17, 1L << 0, ft_close, d);
	mlx_loop(d->mlx);
}
