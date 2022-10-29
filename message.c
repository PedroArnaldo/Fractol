/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parnaldo <parnaldo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:15:18 by parnaldo          #+#    #+#             */
/*   Updated: 2022/10/29 10:44:07 by parnaldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(void)
{
	ft_printf("====CONTROLS====\n");
	ft_printf("move: \n");
	ft_printf("▲ key up\n");
	ft_printf("◄ key left\n");
	ft_printf("▼ key down\n");
	ft_printf("► key right\n");
	ft_printf("Zoom:\n");
	ft_printf("- scroll in\n");
	ft_printf("+ scroll out\n");
}

void	error(void)
{
	ft_printf("Invalid Argument\n");
	ft_printf("To run the program:\n");
	ft_printf("./fractol mondelbrot or");
	ft_printf("./fractol julia number -> (range 1 to 4)\n");
}
