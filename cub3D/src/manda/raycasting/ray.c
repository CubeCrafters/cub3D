#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "../cub3D.h"
#include "render.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

static t_data	*get_texture(t_info *info, int side)
{
	t_data	*texture;

	if (side == 1)
		texture = &info->ea;
	else if (side == 2)
		texture = &info->we;
	else if (side == 3)
		texture = &info->so;
	else
		texture = &info->no;
	return (texture);
}

static void	draw_ver_line(t_info *info, t_render *data, int x, double wallX)
{
	const t_data	*texture = get_texture(info, data->side);
	t_ipoint		tex;
	char			*pixel;
	int				y;

	tex.x = (int)(wallX * (double)texture->width);
	if ((data->side == 0 && info->user->dir.x > 0) \
		|| (data->side == 2 && info->user->dir.y < 0))
		tex.x = texture->width - tex.x - 1;
	double step = 1.0 * texture->height / (data->drawend - data->drawstart);
	double texPos = (data->drawstart - SCREEN_HEIGHT / 2 + \
				 (data->drawend - data->drawstart) / 2) * step;
	y = data->drawstart;
	while (y < data->drawend)
	{
		tex.y = (int)texPos & (texture->height - 1);
		texPos += step;
		pixel = texture->addr + (tex.y * texture->line_length + tex.x * (texture->bits_per_pixel / 8));
		my_mlx_pixel_put(&info->img, x, y, *(unsigned int *)pixel);
		y++;
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

void	ray_casting(t_info *info)
{
	t_render	data;
	double		wall_x;
	int			x;

	color_background(info);
	data.plane = getpuv(info->user->dir);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		set_data(info, &data, x);
		calc_side(info, &data);
		calc_lineheight(info, &data);
		data.drawstart = -data.lineheight / 2 + SCREEN_HEIGHT / 2;
		data.drawend = data.lineheight / 2 + SCREEN_HEIGHT / 2;
		if (data.side <= 1)
			wall_x = info->user->pos.y + data.perpwalldist * data.raydir.y;
		else
			wall_x = info->user->pos.x + data.perpwalldist * data.raydir.x;
		wall_x -= floor(wall_x);
		draw_ver_line(info, &data, x, wall_x);
		x++;
	}
	calc_render_speed(info);
}
