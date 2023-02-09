/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:58:35 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 05:25:32 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * the function where the julia set is called 
 */
void	print_move_julia(int keycode)
{
	if (keycode == 2)
	{
		ft_printf("\e[0;36mRight Move\e[0m\n");
	}
	if (keycode == 0)
	{
		ft_printf("\e[0;32mLeft  Move\e[0m\n");
	}
	if (keycode == 13)
	{
		ft_printf("\e[0;33mUp    Move\e[0m\n");
	}
	if (keycode == 1)
	{
		ft_printf("\e[0;35mDown  Move\e[0m\n");
	}
}

void	move_julia(t_data *mlx, int keycode)
{
	if (keycode == 2)
	{
		mlx->re_move -= 0.1;
		draw_julia(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 0)
	{
		mlx->re_move += 0.1;
		draw_julia(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 13)
	{
		mlx->im_move += 0.1;
		draw_julia(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 1)
	{
		mlx->im_move -= 0.1;
		draw_julia(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
}

int	move_hook_julia(int keycode, t_data *mlx)
{
	if (keycode == 53)
		esc_destroy(mlx);
	if (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1)
		move_julia(mlx, keycode);
	if (keycode >= 123 && keycode <= 126)
		change_c_value(mlx, keycode);
	if (keycode == 18 || keycode == 19
		|| keycode == 20 || keycode == 21 || keycode == 23)
		change_color_julia(mlx, keycode);
	if (keycode == 24 || keycode == 27)
		change_itr(mlx, keycode);
	if (keycode == 15)
		reset_julia(mlx, keycode);
	return (0);
}

void	init_data_julia(t_data *img, double x_move, double y_move)
{
	img->width = 1000;
	img->height = 1000;
	img->rand_color = 100;
	img->y_move = y_move;
	img->y_move_back = y_move;
	img->x_move = x_move;
	img->x_move_back = x_move;
	img->re_move = 0.0;
	img->im_move = 0.0;
	img->max = 100;
	img->base_clr = 0x160C1D;
	img->scale = 4.0 / img->width;
}

int	julia(double x_move, double y_move)
{
	t_data	img;

	init_data_julia(&img, x_move, y_move);
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.height, img.width, "julia!");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_julia(&img);
	mlx_hook(img.mlx_win, 02, 1L << 17, move_hook_julia, &img);
	mlx_hook(img.mlx_win, 17, 1l << 17, close_grace_julia, &img);
	mlx_hook(img.mlx_win, 4, 0, mouse_hook_julia, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
