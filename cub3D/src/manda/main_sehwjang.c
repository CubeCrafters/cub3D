/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/07/31 06:40:06 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "cub3D.h"
#include "./utils/utils.h"
#include <math.h>
#include "./raycasting/matrix.h"
int key_press(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(info->mlx, info->mlx_win);
		exit(0);
	}
	if (keycode == KEY_W)
	{
		info->user->pos.x += info->movespeed * info->user->dir.x;
		info->user->pos.y += info->movespeed * info->user->dir.y;
	}
	if (keycode == KEY_S) { // ESC 키의 keycode는 53
		info->user->pos.x -= info->movespeed * info->user->dir.x;
		info->user->pos.y -= info->movespeed * info->user->dir.y;
	}
	if (keycode == KEY_A)
		rotate_point(&info->user->dir, -info->rotspeed);
	if (keycode == KEY_D)
		rotate_point(&info->user->dir, info->rotspeed);
	mlx_clear_window(info->mlx, info->mlx_win);
	info->img.img = mlx_new_image(info->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.img, &(info->img).bits_per_pixel, \
	&info->img.line_length, &info->img.endian);
	draw(info);
	return 0;
}

int main(int argc, char *argv[]){
	t_info	*info;

	argc=0;(void)argv;//todelete
	info = (t_info *)malloc(sizeof(t_info));
	init_info(info);//parsed_data;
	//parse(info, argv);
	draw(info);
	mlx_hook(info->mlx_win, DESTROY_NOTIFY, 0, close_window, info);
	mlx_key_hook(info->mlx_win, key_press, info);
	mlx_hook(info->mlx_win, 2, (1L<<0)  , key_press, info);
	//mlx_hook(info->mlx_win, 3, (1L<<1), key_release, info);
	mlx_loop_hook(info->mlx, (void *)draw, info);
	mlx_loop(info->mlx);
}

