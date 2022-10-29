/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:15:29 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/29 10:42:33 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_define(t_fractol *fractol, int set)
{
	if (set == 1)
	{
		fractol->c_r = -0.835;
		fractol->c_i = -0.2321;
	}
	else if (set == 2)
	{
		fractol->c_r = -0.8;
		fractol->c_i = 0.156;
	}
	else if (set == 3)
	{
		fractol->c_r = 0.0;
		fractol->c_i = -0.8;
	}
	else if (set == 4)
	{
		fractol->c_r = -0.7269;
		fractol->c_i = 0.1889;
	}
	draw(fractol);
}

void	julia_set(t_fractol *fractol, t_data data, double zi, double zr)
{
	int		n;
	double	tmp;
	int		is_set;

	n = -1;
	is_set = 1;
	while (++n < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + fractol->c_i;
		zr = zr * zr - zi * zi + fractol->c_r;
		zi = tmp;
	}
	if (!is_set)
		paint_iteration(n, &data, fractol->x, fractol->y);
}
