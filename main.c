/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:58:35 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/15 04:32:27 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
/*
 * the main function where every program is executed
 * 
 */
int	main(int ac, char **av)
{
	if (ac > 1)
	{
		if ((ft_strncmp(av[1], "mandelbrot", 11) == 0))
			mandelbrot();
		if ((ft_strncmp(av[1], "burningship", 12) == 0))
			burning_ship();
		if ((ft_strncmp(av[1], "julia", 5) == 0))
		{
			if (ac == 4)
			{
				if ((ft_atof(av[2]) <= 2.0 && ft_atof(av[2]) >= -2.0)
					&& (ft_atof(av[3]) <= 2.0 && ft_atof(av[3]) >= -2.0))
					julia(ft_atof(av[2]), ft_atof(av[3]));
				ft_printf("\033[0;31m\n\n\
				Error!! Range Must be Between '-2' and '2' !\n\033[0m\n\n");
				return (0);
			}
			print_julia_args();
			return (0);
		}
		print_unknown();
		return (0);
	}
	print_error_argument();
}
