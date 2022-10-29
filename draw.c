/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:12:33 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/29 09:30:53 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	color(int r, int g, int b)
{
	int	color;

	color = 0;
	color = color |(r << 16);
	color = color |(g << 8);
	color = color | b;
	return (color);
}

static void	select_fractol(t_fractol *f, t_data data)
{
	if (f->type == 0)
		mandelbrot_set(f, f->x, f->y, data);
	if (f->type == 1)
		julia_set(f, data, f->pi, f->pr);
	if (f->type == 2)
		burningship_set(f, f->x, f->y, data);
}

void	draw(t_fractol *f)
{
	t_data	data;

	data.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	f->y = -1;
	while (++f->y < HEIGHT)
	{
		f->x = -1;
		while (++f->x < WIDTH)
		{
			f->pr = f->min_r + f->x * (f->max_r - f->min_r) / WIDTH;
			f->pi = f->min_i + f->y * (f->max_i - f->min_i) / HEIGHT;
			select_fractol(f, data);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, data.img, 0, 0);
}
