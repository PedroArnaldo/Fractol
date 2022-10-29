/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:57:24 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/29 11:18:11 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	start_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->min_r = -2.0;
	fractol->max_r = 2.0;
	fractol->min_i = -2;
	fractol->max_i = 2;
	fractol->type = 0;
	fractol->zoom = 1.0;
	fractol->zr = 0;
	fractol->zi = 0;
	fractol->is_set = 1;
	fractol->iteration = -1;
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "fract-ol");
}

void	check_julia(char **argv, t_fractol *fractol)
{
	int	julia_set;

	julia_set = ft_atoi(argv[2]);
	if (julia_set >= 1 && julia_set <= 4)
	{
		start_fractol(fractol);
		fractol->type = 1;
		julia_define(fractol, ft_atoi(argv[2]));
	}
	else
	{
		error();
		exit(1);
	}
}

void	check_arg(int argc, char **argv, t_fractol *fractol, int len)
{
	if (len != 10 && len != 5 && len != 11)
	{
		error();
		exit(1);
	}
	if (ft_strnstr(argv[1], "burningship", 11) && argc == 2)
	{
		start_fractol(fractol);
		fractol->type = 2;
		draw(fractol);
	}
	else if (ft_strnstr(argv[1], "mandelbrot", 10) && argc == 2)
	{
		start_fractol(fractol);
		draw(fractol);
	}
	else if (ft_strnstr(argv[1], "julia", 5) && argc == 3)
	{
		check_julia(argv, fractol);
	}
	else
	{
		error();
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;
	int			len;

	if (argc < 2)
	{
		error();
		exit(1);
	}
	len = ft_strlen(argv[1]);
	check_arg(argc, argv, &fractol, len);
	menu();
	mlx_hook(fractol.win, 2, 0, key_event, &fractol);
	mlx_hook(fractol.win, 17, 0, close_win_mouse, &fractol);
	mlx_mouse_hook(fractol.win, zoom_mouse, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
