/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:57:24 by parnaldo          #+#    #+#             */
/*   Updated: 2022/11/01 11:53:48 by parnaldo         ###   ########.fr       */
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

static void	check_julia(char **argv, t_fractol *fractol, int argc)
{
	int	julia_set;

	if (argc == 3)
	{
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
	else
	{
		error();
		exit(1);
	}
}

static void	check_arg(int argc, char **argv, t_fractol *fractol)
{
	if (argc == 2 && !ft_strncmp(argv[1], "burningship", 12))
	{
		start_fractol(fractol);
		fractol->type = 2;
		draw(fractol);
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", 11) && argc == 2)
	{
		start_fractol(fractol);
		draw(fractol);
	}
	else if (!ft_strncmp(argv[1], "julia", 6) && (argc == 3 || argc == 4))
	{
		check_julia(argv, fractol, argc);
	}
	else
	{
		error();
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	if ((argc < 2) || (argc > 3))
	{
		error();
		exit(1);
	}
	check_arg(argc, argv, &f);
	mlx_string_put(f.mlx, f.win, 6, 15, 16777215, "Controls");
	mlx_string_put(f.mlx, f.win, 6, 25, 16777215, "move: arrow key");
	mlx_string_put(f.mlx, f.win, 6, 35, 16777215, "zoom: scroll");
	menu();
	mlx_hook(f.win, 2, 0, key_event, &f);
	mlx_hook(f.win, 17, 0, close_win_mouse, &f);
	mlx_mouse_hook(f.win, zoom_mouse, &f);
	mlx_loop(f.mlx);
	return (0);
}
