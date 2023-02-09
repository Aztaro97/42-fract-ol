/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:58:35 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 05:30:58 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * event handler specifically for the mandelbrot
 */
int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	x++;
	y++;
	mlx_clear_window(img->mlx, img->mlx_win);
	if (keycode == 5)
	{
		ft_printf("\e[0;36mZoom Out\e[0m\n");
		img->scale *= 1.1;
	}
	if (keycode == 4)
	{
		ft_printf("\e[0;34mZoom In\e[0m\n");
		img->scale /= 1.1;
	}
	draw_mandelbrot(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

void	reset_mandelbrot(t_data *mlx, int keycode)
{
	if (keycode == 15)
	{
		ft_printf("\x1b[35m");
		ft_printf("reseted\n");
		ft_printf("\x1b[35m");
		mlx->base_clr = 0x160C1D;
		mlx->x_move = 0.0;
		mlx->y_move = 0.0;
		mlx->max = 100;
		mlx->scale = 4.6 / mlx->width;
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
}

void	change_color_mandelbrot(t_data *mlx, int keycode)
{
	print_color(keycode);
	if (keycode >= 18 && keycode <= 21)
	{
		if (keycode == 18)
			mlx->base_clr = COLLOR1;
		if (keycode == 19)
			mlx->base_clr = COLLOR2;
		if (keycode == 20)
			mlx->base_clr = COLLOR3;
		if (keycode == 21)
			mlx->base_clr = COLLOR4;
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 23)
	{
		mlx->base_clr = 0xffaabb * mlx->rand_color;
		mlx->rand_color += 100;
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
}

void	change_itr_mandelbrot(t_data *mlx, int keycode)
{
	if (keycode == 24)
	{
		if (mlx->max < 1000)
		{
			ft_printf("\e[0;32mIteration Increased\e[0m\n");
			mlx->max += 10;
			draw_mandelbrot(mlx);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
		}
		if (mlx->max == 1000)
			ft_printf("\x1b[35mReached the Maximum Iteration!\x1b[35m\n");
	}
	if (keycode == 27)
	{
		if (mlx->max > 100)
		{
			ft_printf("\e[0;33mIteration Decreased\e[0m\n");
			mlx->max -= 10;
			draw_mandelbrot(mlx);
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
		}
		if (mlx->max == 100)
			ft_printf("\x1b[35mReached the Minimum Iteration!\x1b[35m\n");
	}
}
