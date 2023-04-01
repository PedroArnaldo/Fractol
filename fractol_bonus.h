/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:44:39 by parnaldo          #+#    #+#             */
/*   Updated: 2022/11/01 11:31:30 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#	ifndef FRACTOL_H
# define FRACTOL_H

# include "./libs/libft/libft.h"
# include <stdlib.h>
# include <math.h>

# ifdef __linux__
#  include "mlx_linux/mlx.h"
# else
#  include "mlx/mlx.h"
# endif

# define MAX_ITER 200
# define WIDTH 800
# define HEIGHT 800

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	double	pr;
	double	pi;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	c_r;
	double	c_i;
	double	zoom;
	double	zr;
	double	zi;
	double	tmp;
	int		is_set;
	int		iteration;
	int		type;
	double	x;
	double	y;
}	t_fractol;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int		key_event(int keycode, t_fractol *fractol);
int		close_win_mouse(t_fractol *fractol);
int		zoom_mouse(int keycode, int x, int y, t_fractol *fractol);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		color(int r, int g, int b);
void	julia_define(t_fractol *fractol, int set);
void	julia_set(t_fractol *fractol, t_data data, double zi, double zr);
void	paint_iteration(int iteration, t_data *data, int x, int y);
void	mandelbrot_set(t_fractol *fractol, int x, int y, t_data data);
void	initializer_img(t_fractol *fractol, t_data *data);
void	draw(t_fractol *fractol);
void	menu(void);
void	error(void);
void	burningship_set(t_fractol *fractol, int x, int y, t_data data);

#endif
