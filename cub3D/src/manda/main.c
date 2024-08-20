/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/08/21 07:07:26 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "render.h"
#include "matrix.h"
#include "utils.h"
#include <stdio.h>

int	key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	if (keycode == KEY_W)
		key_w(info);
	if (keycode == KEY_S)
		key_s(info);
	if (keycode == KEY_A)
		rotate_point(&info->user->dir, -info->rotspeed);
	if (keycode == KEY_D)
		rotate_point(&info->user->dir, info->rotspeed);
	mlx_clear_window(info->mlx, info->win);
	info->img.img = mlx_new_image(info->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.img, \
	&(info->img).bits_per_pixel, &info->img.line_length, &info->img.endian);
	draw(info);
	return (0);
}

int	exit_game(int key_val, t_info *data)
{
	(void) key_val;
	(void) data;
	exit(0);
	return (0);
}

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
