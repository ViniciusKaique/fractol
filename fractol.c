/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinpache <vinpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:38:38 by vinpache          #+#    #+#             */
/*   Updated: 2025/09/12 15:51:18 by vinpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static long double	ft_parse_frac(const char *str)
{
	long double	frac;
	long double	div;

	frac = 0.0;
	div = 10.0;
	while (*str >= '0' && *str <= '9')
	{
		frac += (*str - '0') / div;
		div *= 10.0;
		str++;
	}
	return (frac);
}

static long double	ft_atold(const char *str)
{
	long double	result;
	long double	frac;
	int			sign;

	result = 0.0;
	frac = 0.0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		frac = ft_parse_frac(str);
	}
	return (sign * (result + frac));
}

static void	print_usage(void)
{
	write(2, "./fractol Mandelbrot\n", 21);
	write(2, "./fractol Julia <a> <b>\n", 24);
	write(2, "./fractol Burning_Ship\n", 23);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data		data;
	long double	a;
	long double	b;

	if (ac < 2)
		print_usage();
	if (ft_strcmp(av[1], "Mandelbrot") == 0 && ac == 2)
		mandelbrot(&data);
	else if (ft_strcmp(av[1], "Julia") == 0 && ac == 4)
	{
		a = ft_atold(av[2]);
		b = ft_atold(av[3]);
		julia(&data, a, b);
	}
	else if (ft_strcmp(av[1], "Burning_Ship") == 0 && ac == 2)
		burningship(&data);
	else
		print_usage();
	return (0);
}
