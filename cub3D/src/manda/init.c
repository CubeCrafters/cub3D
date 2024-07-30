#include "cub3D.h"
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <math.h>

int maze[12][25] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static void	exit_msg(const char *str)
{
	printf("%s", str);
	exit(1);
}

static t_user	*set_user(double pos_x, double pos_y, double dir_x, double dir_y)
{
	t_user	*user;

	user = (t_user *)malloc(sizeof(user));
	user->pos.x = pos_x;
	user->pos.y = pos_y;
	user->dir.x = dir_x;
	user->dir.y = dir_y;
	user->camera.x = fabs(pos_y) / sqrt(pos_x * pos_x + pos_y * pos_y);
	user->camera.y = -fabs(pos_x) / sqrt(pos_x * pos_x + pos_y * pos_y);
	return (user);
}

static void	init_mlx_datas(t_info *info)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	if (mlx == NULL)
		exit_msg("mlx error\n");
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world!");
	if (mlx_win == NULL)
		exit_msg("mlx error\n");
	img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (img.img == NULL)
		exit_msg("mlx error\n");
	img.img = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &(img).bits_per_pixel, \
	&img.line_length, &img.endian);
	info->mlx = mlx;
	info->mlx_win = mlx_win;
	info->img = img;
	info->map = maze;
}

void	init_info(t_info *info)
{
	t_user	*user;

	init_mlx_datas(info);
	user = set_user(4.0, 1.0, 0.0, 1.0);//parse
	info->user = user;
}