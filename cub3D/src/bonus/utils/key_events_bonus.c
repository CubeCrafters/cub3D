/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:16 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:43:39 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include "matrix_bonus.h"
#include "render_bonus.h"

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
		rotate_point(&info->user->dir, info->rotspeed);
	if (keycode == KEY_D)
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
