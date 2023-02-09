/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:31:52 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 06:01:31 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "./mlx/mlx.h"
# include "./ft_printf/libft.h"  
# include <math.h>
# define COLLOR1 0x2c1d
# define COLLOR2 0x0C1D16
# define COLLOR3 0x3e502c
# define COLLOR4 0xfeaa5aec
/*
*@s_atof: contains the variables i used in the ft_atof function
*/
typedef struct s_atof
{
	long double	res;
	int			x;
	double		inde;
	int			flag;
	int			check;
	double		sign;
}	t_atof;
/*
*@s_data: contains the variables i used in the like the whole program
*/
typedef struct s_data
{
	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	scale;
	int		height;
	int		width;
	int		max;
	int		row;
	int		rand_color;
	int		view;
	int		col;
	int		iteration;
	double	real_arg;
	double	imag_arg;
	int		has_args;
	int		max_itr;
	int		base_clr;
	double	x_move;
	double	x_move_back;
	double	y_move;
	double	y_move_back;
	double	re_move;
	double	im_move;
	double	c_re;
	double	c_im;
	double	x_new;
}			t_data;

/*
 * just including all the parameter of my functions! 
 */
int		mandelbrot(void);
double	ft_atof(char *s);
int		burning_ship(void);
void	print_unknown(void);
void	print_msg(int keycode);
void	print_julia_args(void);
void	draw_julia(t_data *img);
int		close_grace(t_data *mlx);
void	print_color(int keycode);
void	esc_destroy(t_data *mlx);
void	print_error_argument(void);
void	draw_mandelbrot(t_data *img);
void	draw_burningship(t_data *img);
int		close_grace_julia(t_data *mlx);
int		julia(double x_move, double y_move);
void	move_julia(t_data *mlx, int keycode);
int		close_grace_burningship(t_data *mlx);
void	change_itr(t_data *mlx, int keycode);
void	reset_julia(t_data *mlx, int keycode);
int		esc_exit_hook(int keycode, t_data *mlx);
void	change_c_value(t_data *mlx, int keycode);
int		hooks_hook_julia(int keycode, t_data *mlx);
void	reset_mandelbrot(t_data *mlx, int keycode);
void	reset_burningship(t_data *mlx, int keycode);
void	change_color_julia(t_data *mlx, int keycode);
void	move_hook_mandelbrot(t_data *mlx, int keycode);
void	change_itr_mandelbrot(t_data *mlx, int keycode);
void	move_hook_burningship(t_data *mlx, int keycode);
void	change_itr_burningship(t_data *mlx, int keycode);
void	change_color_mandelbrot(t_data *mlx, int keycode);
void	change_color_burningship(t_data *mlx, int keycode);
int		mouse_hook(int keycode, int x, int y, t_data *img);
int		esc_exit_hook_burningship(int keycode, t_data *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		mouse_hook_julia(int keycode, int x, int y, t_data *img);
int		mouse_hook_burningship(int keycode, int x, int y, t_data *img);

#endif