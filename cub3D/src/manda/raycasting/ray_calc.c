#include "render.h"

void calc_side(t_info *info, t_render *data)
{
	int hit = 0;
	while (hit == 0)
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
			hit = 1;
	}
}

void calc_render_speed(t_info *info)
{
	struct timeval oldtime;

	oldtime = info->time;
	gettimeofday(&info->time, NULL);
	double frameTime = diff_tv(&info->time, &oldtime) / 1000000.0;
	info->movespeed = frameTime * 5.0;
	info->rotspeed = frameTime * 3.0;
}

void calc_lineheight(t_info *info, t_render *data)
{
	if (data->side <= 1)
		data->perpwalldist = (data->map.x - info->user->pos.x + (1 - data->step.x) / 2) / data->raydir.x;
	else
		data->perpwalldist = (data->map.y - info->user->pos.y + (1 - data->step.y) / 2) / data->raydir.y;
	data->lineheight = (int)(SCREEN_HEIGHT / data->perpwalldist);
}