/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:57:24 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/29 13:24:14 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

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

	if(argc == 4)
	{
	   fractol->c_r = ft_atod(argv[2]);
	   fractol->c_i = ft_atod(argv[3]);
	   start_fractol(fractol);
	   fractol->type = 1;
	   draw(fractol);
	}
	else if(argc == 3)
	{
		julia_set = ft_atoi(argv[2]);
		if (julia_set >= 1 && julia_set <= 4)
		{
			ft_printf("julia");
			start_fractol(fractol);
			fractol->type = 1;
			julia_define(fractol, ft_atoi(argv[2]));
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
	if ( argc == 2 && !ft_strncmp(argv[1], "burningship", 12))
	{
		ft_printf("burninship");
		start_fractol(fractol);
		fractol->type = 2;
		draw(fractol);
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", 11) && argc == 2)
	{
		ft_printf("mandelbrot");
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
	t_fractol	fractol;
	
	if (argc < 2)
	{
		error();
		exit(1);
	}
	printf("double: %d\n", argc);
	check_arg(argc, argv, &fractol);
	menu();
	mlx_hook(fractol.win, 2, 0, key_event, &fractol);
	mlx_hook(fractol.win, 17, 0, close_win_mouse, &fractol);
	mlx_mouse_hook(fractol.win, zoom_mouse, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
