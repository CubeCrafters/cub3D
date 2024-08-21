/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:01:02 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:44:18 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"

void	calc_side(t_info *info, t_render *data)
{
	while (1)
	{
		if (data->sidedist.x < data->sidedist.y)
		{
			data->sidedist.x += data->deltadist.x;
			data->map.x += data->step.x;
			if (data->raydir.x > 0)
				data->side = 0;
			else
				data->side = 1;
		}
		else
		{
			data->sidedist.y += data->deltadist.y;
			data->map.y += data->step.y;
			if (data->raydir.y > 0)
				data->side = 2;
			else
				data->side = 3;
		}
		if (info->map[data->map.x][data->map.y] == '1')
			return ;
	}
}

void	calc_render_speed(t_info *info)
{
	struct timeval	oldtime;
	double			frametime;

	oldtime = info->time;
	gettimeofday(&info->time, NULL);
	frametime = diff_tv(&info->time, &oldtime) / 1000000.0;
	info->movespeed = frametime * 5.0;
	info->rotspeed = frametime * 3.0;
}

void	calc_lineheight(t_info *info, t_render *data)
{
	if (data->side <= 1)
		data->perpwalldist = (data->map.x - info->user->pos.x \
							+ (1 - data->step.x) / 2) / data->raydir.x;
	else
		data->perpwalldist = (data->map.y - info->user->pos.y \
							+ (1 - data->step.y) / 2) / data->raydir.y;
	data->lineheight = (int)(SCREEN_HEIGHT / data->perpwalldist);
}

void	calc_dist(t_info *info, t_render *data)
{
	if (data->raydir.x < 0)
	{
		data->step.x = -1;
		data->sidedist.x = (info->user->pos.x - data->map.x) \
							* data->deltadist.x;
	}
	else
	{
		data->step.x = 1;
		data->sidedist.x = (data->map.x + 1.0 - info->user->pos.x) \
							* data->deltadist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->sidedist.y = (info->user->pos.y - data->map.y) \
							* data->deltadist.y;
	}
	else
	{
		data->step.y = 1;
		data->sidedist.y = (data->map.y + 1.0 - info->user->pos.y) \
							* data->deltadist.y;
	}
}

long long	diff_tv(struct timeval *tv1, struct timeval *tv2)
{
	long long	sec_diff;
	long long	usec_diff;

	sec_diff = tv1->tv_sec - tv2->tv_sec;
	usec_diff = tv1->tv_usec - tv2->tv_usec;
	return (sec_diff * 1000000 + usec_diff);
}
