/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:03:05 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:42:40 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>

static void	set_dir(t_user *user, char dir)
{
	if (dir == 'N')
	{
		user->dir.x = -1.0;
		user->dir.y = 0;
	}
	if (dir == 'E')
	{
		user->dir.x = 0;
		user->dir.y = 1.0;
	}
	if (dir == 'W')
	{
		user->dir.x = 0;
		user->dir.y = -1.0;
	}
	if (dir == 'S')
	{
		user->dir.x = 1.0;
		user->dir.y = 0;
	}
	return ;
}

t_user	*set_user(int x, int y, char dir)
{
	t_user			*user;
	const double	pos_x = (double)x;
	const double	pos_y = (double)y;

	user = (t_user *)malloc(sizeof(t_user));
	if (user == NULL)
		print_error("Malloc Error");
	user->pos.x = pos_x + 0.5;
	user->pos.y = pos_y + 0.5;
	set_dir(user, dir);
	user->camera.x = fabs(pos_y) / sqrt(pos_x * pos_x + pos_y * pos_y);
	user->camera.y = -fabs(pos_x) / sqrt(pos_x * pos_x + pos_y * pos_y);
	return (user);
}

void	init_mlx_datas(t_info *info)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (mlx == NULL)
		print_error("mlx error\n");
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world!");
	if (mlx_win == NULL)
		print_error("mlx error\n");
	img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (img.img == NULL)
		print_error("mlx error\n");
	img.addr = mlx_get_data_addr(img.img, &(img).bits_per_pixel, \
	&img.line_length, &img.endian);
	info->mlx = mlx;
	info->win = mlx_win;
	info->img = img;
}
