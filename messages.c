/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:22:43 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 04:54:39 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * functions which print certain message to the stdout
 */
void	print_error_argument(void)
{
	ft_printf("\n\n\t\
	 _______________________________________________\n\t\t|\t\t\t\t\t\t|");
	ft_printf("\n\t\t|\t\033[0;31mIncorrect Number of argument\033[0m\t\t|\n");
	ft_printf("\t\t|\t\033[0;33mUsage\033[0m ./fractal <FRACTOL_NAME>\t\t|\n");
	ft_printf("\t\t|\t\t\e[1;34mFRACTOL_NAME\033[0m\t\t\t|\n\e[0m");
	ft_printf("\t\t|\t\e[0;35m1.mandelbrot\e[0m\t\t\t\t|\n\t\t|\t\e[0;35m2.julia\e[0m\t\t\t\t\t|\n\t\t|\
	\e[0;35m3.burningship\e[0m\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n");
	ft_printf("\t\t -----------------------------------------------\n\t\t\n");
}

void	print_unknown(void)
{
	ft_printf("\n\n\t\
	 _______________________________________________\n\t\t|\t\t\t\t\t\t|");
	ft_printf("\n\t\t|\t\033[0;31mUNKNOWN FRACTAL NAME!\033[0m\t\t\t|\n");
	ft_printf("\t\t|\t\e[1;34mList of Fractal names\e[0m\t\t\t|\n");
	ft_printf("\t\t|\t\e[0;35m1.mandelbrot\e[0m\t\t\t\t|\n\t\t|\t\e[0;35m2.julia\e[0m\t\t\t\t\t|\n\t\t|\
	\e[0;35m3.burningship\e[0m\t\t\t\t|\n\t\t|\t\t\t\t\t\t|\n");
	ft_printf("\t\t -----------------------------------------------\n\t\t\n");
}

void	print_julia_args(void)
{
	ft_printf("\n\n\t\
	 _______________________________________________\n\t\t|\t\t\t\t\t\t|\n");
	ft_printf("\t\t|\t\t\033[0;31mINCORRECT USAGE!\033[0m\t\t|\n");
	ft_printf("\t\t|\t\e[1;34mUSAGE ./fractal julia <n1> <n2>\e[0m\t\t|\n");
	ft_printf("\t\t|\t\e[1;34mExample ./fractal julia 1.0 1.0\e[0m\t\t|\n");
	ft_printf("\t\t|\tn1,n2 >= -2.0 AND n1,n2 <= 2.0 \e[0m\t\t|\n\t\t|\t\t\t\t\t\t|\n");
	ft_printf("\t\t -----------------------------------------------\n\t\t\n");
}

void	print_msg(int keycode)
{
	if (keycode == 124)
		ft_printf("\e[0;36mRight Move\e[0m\n");
	if (keycode == 123)
		ft_printf("\e[0;32mLeft  Move\e[0m\n");
	if (keycode == 125)
		ft_printf("\e[0;33mUp    Move\e[0m\n");
	if (keycode == 126)
		ft_printf("\e[0;35mDown  Move\e[0m\n");
}

void	print_color(int keycode)
{
	if (keycode == 18)
	{
		ft_printf("\e[0;33mColor changed\e[0m\n");
	}
	if (keycode == 19)
	{
		ft_printf("\e[0;33mColor changed\e[0m\n");
	}
	if (keycode == 20)
	{
		ft_printf("\e[0;33mColor changed\e[0m\n");
	}
	if (keycode == 21)
	{
		ft_printf("\e[0;33mColor changed\e[0m\n");
	}
	if (keycode == 23)
	{
		ft_printf("\e[0;33mRandom Color changed\e[0m\n");
	}
}
