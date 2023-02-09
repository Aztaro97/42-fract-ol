/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:58:35 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 05:38:50 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * the function where the burningship set is called 
 */
int	lop_burnigship(t_data *img)
{
	double	x;
	double	y;
	int		iteration;
	double	x_new;

	x = img->c_re;
	y = img->c_im;
	iteration = 0;
	while (x * x + y * y <= 4 && iteration < img->max)
	{
		x_new = x * x - y * y + img->c_re;
		y = fabs(2 * x * y) + img->c_im;
		x = x_new;
		iteration++;
	}
	return (iteration);
}

void	draw_burningship(t_data *img)
{
	int	iteration;

	img->row = 0;
	mlx_clear_window(img->mlx, img->mlx_win);
	while (img->row < img->height)
	{
		img->col = 0;
		while (img->col < img->width)
		{
			img->c_re = (img->x_move + (img->col - img->width / 2.0)
					* img->scale);
			img->c_im = (img->y_move + (img->row - img->height / 2.0)
					* img->scale);
			iteration = lop_burnigship(img);
			if (iteration == img->max)
				my_mlx_pixel_put(img, img->col, img->row, 0x000000);
			else
				my_mlx_pixel_put(img, img->col, img->row, img->base_clr
					* iteration);
			img->col++;
		}
		img->row++;
	}
}

void	move_hook_burningship(t_data *mlx, int keycode)
{
	print_msg(keycode);
	if (keycode == 124)
	{
		mlx->x_move -= 0.1;
		draw_burningship(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 123)
	{
		mlx->x_move += 0.1;
		draw_burningship(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 125)
	{
		mlx->y_move -= 0.1;
		draw_burningship(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
	if (keycode == 126)
	{
		mlx->y_move += 0.1;
		draw_burningship(mlx);
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->img, 0, 0);
	}
}

int	esc_exit_hook_burningship(int keycode, t_data *mlx)
{
	if (keycode == 53)
		esc_destroy(mlx);
	if (keycode >= 123 && keycode <= 126)
		move_hook_burningship(mlx, keycode);
	if (keycode == 24 || keycode == 27)
		change_itr_burningship(mlx, keycode);
	if (keycode >= 18 && keycode <= 23)
		change_color_burningship(mlx, keycode);
	if (keycode == 15)
		reset_burningship(mlx, keycode);
	return (0);
}

int	burning_ship(void)
{
	t_data	img;

	img.width = 1000;
	img.height = 1000;
	img.x_move = 0.0;
	img.re_move = 0.0;
	img.im_move = 0.0;
	img.y_move = 0.0;
	img.max = 100;
	img.base_clr = 0x160C1D;
	img.scale = 4.6 / img.width;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, img.height, img.width, "Burningship");
	img.img = mlx_new_image(img.mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_burningship(&img);
	mlx_hook(img.mlx_win, 02, 1L << 17, esc_exit_hook_burningship, &img);
	mlx_hook(img.mlx_win, 17, 1l << 17, close_grace_burningship, &img);
	mlx_hook(img.mlx_win, 4, 0, mouse_hook_burningship, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
