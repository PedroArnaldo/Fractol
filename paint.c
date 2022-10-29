/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:31:41 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/28 18:48:32 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	paint_larger_eight(int i, int x, int y, t_data *data)
{
	if (i == 8)
		my_mlx_pixel_put(data, x, y, color(134, 181, 229));
	if (i == 9)
		my_mlx_pixel_put(data, x, y, color(211, 236, 248));
	if (i == 10)
		my_mlx_pixel_put(data, x, y, color(241, 233, 191));
	if (i == 11)
		my_mlx_pixel_put(data, x, y, color(248, 201, 95));
	if (i == 12)
		my_mlx_pixel_put(data, x, y, color(255, 170, 0));
	if (i == 13)
		my_mlx_pixel_put(data, x, y, color(204, 128, 0));
	if (i == 14)
		my_mlx_pixel_put(data, x, y, color(153, 87, 0));
	if (i == 15)
		my_mlx_pixel_put(data, x, y, color(106, 52, 3));
}

void	paint_iteration(int iteration, t_data *data, int x, int y)
{
	int	i;

	i = iteration % 16;
	if (i == 0)
		my_mlx_pixel_put(data, x, y, color(66, 30, 15));
	if (i == 1)
		my_mlx_pixel_put(data, x, y, color(25, 7, 26));
	if (i == 2)
		my_mlx_pixel_put(data, x, y, color(9, 1, 47));
	if (i == 3)
		my_mlx_pixel_put(data, x, y, color(4, 4, 73));
	if (i == 4)
		my_mlx_pixel_put(data, x, y, color(0, 7, 100));
	if (i == 5)
		my_mlx_pixel_put(data, x, y, color(12, 44, 138));
	if (i == 6)
		my_mlx_pixel_put(data, x, y, color(24, 82, 177));
	if (i == 7)
		my_mlx_pixel_put(data, x, y, color(57, 125, 209));
	paint_larger_eight(i, x, y, data);
}
