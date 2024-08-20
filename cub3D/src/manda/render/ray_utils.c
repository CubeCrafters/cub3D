/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:01:10 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 07:01:11 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "../cub3D.h"
#include "render.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

void	color_background(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			if (i > SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(&info->img, j, i, info->ceiling);
			else
				my_mlx_pixel_put(&info->img, j, i, info->floor);
			j++;
		}
		i++;
	}
}

void	set_data(t_info *info, t_render *data, int x)
{
	data->camera = 2 * x / (double)SCREEN_WIDTH - 1;
	data->raydir.x = info->user->dir.x + data->plane.x * data->camera;
	data->raydir.y = info->user->dir.y + data->plane.y * data->camera;
	data->map.x = (int)info->user->pos.x;
	data->map.y = (int)info->user->pos.y;
	data->deltadist.x = fabs(1 / data->raydir.x);
	data->deltadist.y = fabs(1 / data->raydir.y);
	calc_dist(info, data);
}
