/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:16 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/22 15:33:51 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "matrix.h"
#include "render.h"

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
		key_a(info);
	if (keycode == KEY_D)
		key_d(info);
	if (keycode == 123)
		rotate_point(&info->user->dir, info->rotspeed);
	if (keycode == 124)
		rotate_point(&info->user->dir, -info->rotspeed);
	mlx_clear_window(info->mlx, info->win);
	info->img.img = mlx_new_image(info->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	info->img.addr = mlx_get_data_addr(info->img.img, \
	&(info->img).bits_per_pixel, &info->img.line_length, &info->img.endian);
	draw(info);
	return (0);
}

void	key_w(t_info *info)
{
	if (info->map[(int)(info->user->pos.x \
						+ info->movespeed * info->user->dir.x)] \
				[(int)(info->user->pos.y + info->movespeed \
						* info->user->dir.y)] != '1')
	{
		info->user->pos.x += info->movespeed * info->user->dir.x;
		info->user->pos.y += info->movespeed * info->user->dir.y;
	}
}

void	key_s(t_info *info)
{
	if (info->map[(int)(info->user->pos.x - \
						- info->movespeed * info->user->dir.x)] \
				[(int)(info->user->pos.y - info->movespeed \
						* info->user->dir.y)] != '1')
	{
		info->user->pos.x -= info->movespeed * info->user->dir.x;
		info->user->pos.y -= info->movespeed * info->user->dir.y;
	}
}

void	key_a(t_info *info)
{
	const t_dpoint	puv = getpuv(info->user->dir);

	if (info->map[(int)(info->user->pos.x + info->movespeed * puv.x)] \
				[(int)(info->user->pos.y + info->movespeed * puv.y)] != '1')
	{
		info->user->pos.x += info->movespeed * puv.x;
		info->user->pos.y += info->movespeed * puv.y;
	}
}

void	key_d(t_info *info)
{
	const t_dpoint	puv = getpuv(info->user->dir);

	if (info->map[(int)(info->user->pos.x - info->movespeed * puv.x)] \
				[(int)(info->user->pos.y - info->movespeed * puv.y)] != '1')
	{
		info->user->pos.x -= info->movespeed * puv.x;
		info->user->pos.y -= info->movespeed * puv.y;
	}
}
