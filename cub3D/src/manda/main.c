/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/08/21 13:34:13 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "render.h"
#include "matrix.h"
#include "utils.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		print_error("this program takes one parameter");
	ft_bzero(&info, sizeof(t_info));
	init_mlx_datas(&info);
	read_arg(av, &info);
	mlx_hook(info.win, X_EVENT_KEY, 0, &exit_game, &info);
	mlx_key_hook(info.win, key_press, &info);
	mlx_hook(info.win, 2, (1L << 0), key_press, &info);
	mlx_loop_hook(info.mlx, (void *)draw, &info);
	mlx_loop(info.mlx);
}
