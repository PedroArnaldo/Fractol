/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:59:51 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/28 13:03:25 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_set(t_fractol *fractol, int x, int y, t_data data)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;

	zr = 0;
	zi = 0;
	n = -1;
	fractol->is_set = 1;
	while (++n < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			fractol->is_set = 0;
			break ;
		}
		tmp = fabs(2 * zr * zi) + fractol->pi;
		zr = zr * zr - zi * zi + fractol->pr;
		zi = tmp;
	}
	if (!(fractol->is_set))
		paint_iteration(n, &data, x, y);
}
