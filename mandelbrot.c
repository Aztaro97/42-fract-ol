/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:58:35 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 05:11:05 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * the function where the mandelbrot set is called 
 */
void	move_hook_mandelbrot(t_data *mlx, int keycode)
{
	print_msg(keycode);
	if (keycode == 124)
	{
		mlx->x_move -= 0.1;
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 123)
	{
		mlx->x_move += 0.1;
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 125)
	{
		mlx->y_move -= 0.1;
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 126)
	{
		mlx->y_move += 0.1;
		draw_mandelbrot(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
}

void	init_data_mandelbrot(t_data *img)
{
	img->width = 1000;
	img->rand_color = 100;
	img->height = 1000;
	img->x_move = 0.0;
	img->re_move = 0.0;
	img->im_move = 0.0;
	img->y_move = 0.0;
	img->max = 100;
	img->base_clr = 0x160C1D;
	img->scale = 4.6 / img->width;
}

int	esc_exit_hook(int keycode, t_data *mlx)
{
	if (keycode == 53)
		esc_destroy(mlx);
	if (keycode >= 123 && keycode <= 126)
		move_hook_mandelbrot(mlx, keycode);
	if (keycode == 24 || keycode == 27)
		change_itr_mandelbrot(mlx, keycode);
	if (keycode >= 18 && keycode <= 23)
		change_color_mandelbrot(mlx, keycode);
	if (keycode == 15)
		reset_mandelbrot(mlx, keycode);
	return (0);
}

int	mandelbrot(void)
{
	t_data	img;

	init_data_mandelbrot(&img);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.height, img.width, "Mandelbrot!");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_mandelbrot(&img);
	mlx_hook(img.mlx_win, 02, 1L << 17, esc_exit_hook, &img);
	mlx_hook(img.mlx_win, 17, 1l << 17, close_grace, &img);
	mlx_hook(img.mlx_win, 4, 0, mouse_hook, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
