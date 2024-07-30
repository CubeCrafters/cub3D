/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/07/31 06:36:52 by sehwjang         ###   ########.fr       */
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
        info->user->pos.x += 0.1 * info->user->dir.x;
		info->user->pos.y += 0.1 * info->user->dir.y;
    }
	if (keycode == KEY_S) { // ESC 키의 keycode는 53
		info->user->pos.x -= 0.1 * info->user->dir.x;
		info->user->pos.y -= 0.1 * info->user->dir.y;
    }
	if (keycode == KEY_A) { // ESC 키의 keycode는 53
		rotate_point(&info->user->dir, -M_PI/6);
    }
	if (keycode == KEY_D) { // ESC 키의 keycode는 53
		rotate_point(&info->user->dir, M_PI/6);
    }
	//printf("pos_x : %lf, pos_y : %lf, dir_x : %lf, dir_y : %lf",)
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
	mlx_hook(info->mlx_win, DESTROY_NOTIFY, 0, close_window, (void *)0);
	mlx_key_hook(info->mlx_win, key_press, info);
	mlx_loop(info->mlx);

}

