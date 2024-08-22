/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:02:17 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/22 17:15:01 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "../cub3D_bonus.h"
#include "render_bonus.h"
#include "matrix_bonus.h"
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

static t_data	*get_texture(t_info *info, int side)
{
	t_data	*texture;

	if (side == 1)
		texture = &info->no;
	else if (side == 2)
		texture = &info->we;
	else if (side == 3)
		texture = &info->ea;
	else
		texture = &info->so;
	return (texture);
}

static void	put_pixel(t_info *info, t_render *data, t_data *texture, int x)
{
	int		y;
	char	*pixel;
	double	step;
	double	texpos;

	step = 1.0 * texture->height / (data->drawend - data->drawstart);
	texpos = (data->drawstart - SCREEN_HEIGHT / 2 \
			+ (data->drawend - data->drawstart) / 2) * step;
	y = data->drawstart;
	while (y < data->drawend)
	{
		data->tex.y = (int)texpos % texture->height;
		if (data->tex.y < 0)
			data->tex.y += texture->height;
		texpos += step;
		pixel = texture->addr + (data->tex.y * texture->line_length \
							+ data->tex.x * (texture->bits_per_pixel / 8));
		my_mlx_pixel_put(&info->img, x, y, *(unsigned int *)pixel);
		y++;
	}
}

static void	draw_ver_line(t_info *info, t_render *data, int x, double wallX)
{
	t_data	*texture;

	texture = get_texture(info, data->side);
	data->tex.x = (int)(wallX * (double)texture->width);
	if ((data->side == 0) || (data->side == 3))
		data->tex.x = texture->width - data->tex.x - 1;
	put_pixel(info, data, texture, SCREEN_WIDTH - x);
}

void	draw(t_info *info)
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
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
