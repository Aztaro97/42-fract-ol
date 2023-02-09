/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:38:58 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 04:31:19 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * this file contains the ESC and (X) Exitings
 */
int	close_grace_julia(t_data *mlx)
{
	ft_printf("\033[1;31m\n\t\
	 _______________________________________________\n\t\t|\t\t\t\t\t\t|\n");
	ft_printf("\t\t|\t\tJulia Destroyed\t\t\t|\n");
	ft_printf("\t\t -----------------------------------------------\n\t\t\n\033[0m");
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(1);
}

int	close_grace(t_data *mlx)
{
	ft_printf("\033[1;31m\n\t\
	 _______________________________________________\n\t\t|\t\t\t\t\t\t|\n");
	ft_printf("\t\t|\t\tMandelbrot Destroyed\t\t|\n");
	ft_printf("\t\t -----------------------------------------------\n\t\t\n\033[0m");
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(1);
	return (0);
}

int	close_grace_burningship(t_data *mlx)
{
	ft_printf("\033[1;31m\n\t\
	 _______________________________________________\n\t\t|\t\t\t\t\t\t|\n");
	ft_printf("\t\t|\t\tburningship Destroyed\t\t|\n");
	ft_printf("\t\t -----------------------------------------------\n\t\t\n\033[0m");
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(1);
	return (0);
}

void	esc_destroy(t_data *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	ft_printf("\033[1;31mProgram Exited!\033[0m\n");
	exit(0);
}
