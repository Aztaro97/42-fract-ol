/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:42:31 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 05:04:52 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * draw the pixels to the graphical interface
 */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	lop_mandel(t_data *img)
{
	double	x;
	double	y;
	int		iteration;
	double	x_new;

	x = 0;
	y = 0;
	iteration = 0;
	while (x * x + y * y <= 4 && iteration < img->max)
	{
		x_new = x * x - y * y + img->c_re;
		y = 2 * x * y + img->c_im;
		x = x_new;
		iteration++;
	}
	return (iteration);
}

void	draw_mandelbrot(t_data *img)
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
			iteration = lop_mandel(img);
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

void	lop_julia(t_data *img)
{
	while (img->c_re * img->c_re + img->c_im * img->c_im <= 4
		&& img->iteration < img->max)
	{
		img->x_new = img->c_re * img->c_re - img->c_im * img->c_im;
		img->c_im = 2 * img->c_re * img->c_im + img->y_move;
		img->c_re = img->x_new + img->x_move;
		img->iteration++;
	}
}

void	draw_julia(t_data *img)
{
	img->row = 0;
	mlx_clear_window(img->mlx, img->mlx_win);
	while (img->row < img->height)
	{
		img->col = 0;
		while (img->col < img->width)
		{
			img->c_re = img->re_move + (img->col - img->width / 2.0)
				* img->scale;
			img->c_im = img->im_move + (img->row - img->height / 2.0)
				* img->scale;
			img->iteration = 0;
			lop_julia(img);
			if (img->iteration == img->max)
				my_mlx_pixel_put(img, img->col, img->row, 0x000000);
			else
				my_mlx_pixel_put(img, img->col, img->row,
					img->base_clr * img->iteration);
			img->col++;
		}
		img->row++;
	}
}
