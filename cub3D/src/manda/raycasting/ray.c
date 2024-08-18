#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "../cub3D.h"
#include "render.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

long long diff_tv(struct timeval *tv1, struct timeval *tv2)
{
	long long sec_diff;
	long long usec_diff;

	sec_diff = tv1->tv_sec - tv2->tv_sec;
	usec_diff = tv1->tv_usec - tv2->tv_usec;
	return (sec_diff * 1000000 + usec_diff);
}

static t_data *get_texture(t_info *info, int side)
{
	t_data *texture;
	if (side == 1)
		texture = &info->ea;
	else if (side == 2)
		texture = &info->we;
	else if (side == 3)
		texture = &info->so;
	else
		texture = &info->no;
	return texture;
}

static void verLine_tex(t_info *info, t_render *data, int x, double wallX)
{
	const t_data *texture = get_texture(info, data->side);
	int texX = (int)(wallX * (double)texture->width);
	int texY;
	char *pixel;

	if ((data->side == 0 && info->user->dir.x > 0) || (data->side == 2 && info->user->dir.y < 0))
		texX = texture->width - texX - 1;
	double step = 1.0 * texture->height / (data->drawend - data->drawstart);
	double texPos = (data->drawstart - SCREEN_HEIGHT / 2 + (data->drawend - data->drawstart) / 2) * step;
	for (int y = data->drawstart; y < data->drawend; y++)
	{
		texY = (int)texPos & (texture->height - 1);
		texPos += step;
		pixel = texture->addr + (texY * texture->line_length + texX * (texture->bits_per_pixel / 8));
		my_mlx_pixel_put(&info->img, x, y, *(unsigned int *)pixel);
	}
}

void set_data(t_info *info, t_render *data, int x)
{
	data->camera = 2 * x / (double)SCREEN_WIDTH - 1;
	data->raydir.x = info->user->dir.x + data->plane.x * data->camera;
	data->raydir.y = info->user->dir.y + data->plane.y * data->camera;
	data->map.x = (int)info->user->pos.x;
	data->map.y = (int)info->user->pos.y;
	data->deltadist.x = fabs(1 / data->raydir.x);
	data->deltadist.y = fabs(1 / data->raydir.y);
	if (data->raydir.x < 0)
	{
		data->step.x = -1;
		data->sidedist.x = (info->user->pos.x - data->map.x) * data->deltadist.x;
	}
	else
	{
		data->step.x = 1;
		data->sidedist.x = (data->map.x + 1.0 - info->user->pos.x) * data->deltadist.x;
	}
	if (data->raydir.y < 0)
	{
		data->step.y = -1;
		data->sidedist.y = (info->user->pos.y - data->map.y) * data->deltadist.y;
		return;
	}
	data->step.y = 1;
	data->sidedist.y = (data->map.y + 1.0 - info->user->pos.y) * data->deltadist.y;
}

void ray_casting(t_info *info)
{
	t_render data;

	double wallX;
	data.plane = getpuv(info->user->dir);
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		set_data(info, &data, x);
		calc_side(info, &data);
		calc_lineheight(info, &data);

		data.drawstart = -data.lineheight / 2 + SCREEN_HEIGHT / 2;
		// if (data.drawstart < 0)
		// 	data.drawstart = 0;
		data.drawend = data.lineheight / 2 + SCREEN_HEIGHT / 2;
		// if (data.drawend >= SCREEN_HEIGHT)
		// 	data.drawend = SCREEN_HEIGHT - 1;
		if (data.side <= 1)
			wallX = info->user->pos.y + data.perpwalldist * data.raydir.y;
		else
			wallX = info->user->pos.x + data.perpwalldist * data.raydir.x;
		wallX -= floor(wallX);
		verLine_tex(info, &data, x, wallX);
	}
	calc_render_speed(info);
}
