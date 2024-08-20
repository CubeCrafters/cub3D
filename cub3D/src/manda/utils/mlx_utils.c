/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:22 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 07:00:22 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"
#include "utils.h"
#include <stdlib.h>
#include <mlx.h>
// int	key_press(int keycode, t_user *user)
// {
// 	if (keycode == 13)
// 		move_user(user, 1);
// 	else if (keycode == 0)
// 		rotate_user(user, 1);
// 	else if (keycode == 1)
// 		move_user(user, -1);
// 	else if (keycode == 2)
// 		rotate_user(user, -1);
// 	else if (keycode == 53)
// 		exit(0);
// 	return (0);
// }

int	close_window(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
