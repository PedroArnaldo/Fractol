/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:44:05 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/29 10:59:03 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move(int keycode, t_fractol *fractol)
{
	if (keycode == 124)
	{
		fractol->min_r += 0.01;
		fractol->max_r += 0.01;
	}
	if (keycode == 123)
	{
		fractol->min_r -= 0.01;
		fractol->max_r -= 0.01;
	}
	if (keycode == 125)
	{
		fractol->min_i += 0.01;
		fractol->max_i += 0.01;
	}
	if (keycode == 126)
	{
		fractol->min_i -= 0.01;
		fractol->max_i -= 0.01;
	}
	mlx_clear_window(fractol->mlx, fractol->win);
	draw(fractol);
}

int	key_event(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	if (keycode >= 123 && keycode <= 126)
	{
		move(keycode, fractol);
	}
	return (0);
}

int	close_win_mouse(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
}

int	zoom_mouse(int keycode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (keycode == 5)
	{
		fractol->min_r *= 1.1;
		fractol->min_i *= 1.1;
		fractol->max_r *= 1.1;
		fractol->max_i *= 1.1;
	}
	if (keycode == 4)
	{
		fractol->min_r *= 0.9;
		fractol->min_i *= 0.9;
		fractol->max_r *= 0.9;
		fractol->max_i *= 0.9;
	}	
	mlx_clear_window(fractol->mlx, fractol->win);
	draw(fractol);
	return (0);
}
