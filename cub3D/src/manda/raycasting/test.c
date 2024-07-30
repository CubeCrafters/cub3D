#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "../../../cub3D.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>

#define DESTROY_NOTIFY	17

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > 25 * 50 || y > 12 * 50)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


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

// void ray(){
// }

void	draw_wall(int x, int y,t_data *data){
	for(int i = (y)*50; i<(y+1)*50;i++){
		for(int j = (x)*50; j<(x+1)*50;j++){
			my_mlx_pixel_put(data, i,j,255);
		}
	}
}

void	draw_map(void *mlx, void *mlx_win, t_data *img){
	
	for(int i = 0 ; i<12; i++){
		for(int j = 0; j< 25; j++){
			if (maze[i][j] == 1)
				draw_wall(i,j,img);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
}


int	draw_user(t_info *info)
{
	double	grad;

	t_user	user = *info->user;
	double my_x = user.pos.x * 50 + 25;
	double my_y = user.pos.y * 50 + 25;
	my_mlx_pixel_put(&info->img, my_x, my_y, 0xFF0000);
	
	if(user.dir.x == 0){

	}
	else{
		rotate_point(&user.dir, -M_PI/6);
		for(int j = 0; j <60;j++ ){
			grad = user.dir.y / user.dir.x;
			for (int i = my_x; i< 25 * 50;i++)
			{
				if (maze[(int)(grad * (i - my_x) + my_y) / 50][i / 50] == 1)
				{	
					my_mlx_pixel_put(&info->img, i, (grad * (i - my_x) + my_y), 0xFFFFFF);
					break ;
				}
				my_mlx_pixel_put(&info->img, i, grad * (i - my_x) + my_y, 0xFF0000);
			}
			rotate_point(&user.dir, M_PI/180);
		}
	}
	return (0);
}

int	close_window(void)
{
	exit(0);
	return (0);
}

void	exit_msg(const char *str)
{
	printf("%s", str);
	exit(1);
}

void	init_mlx_datas(t_info *info)
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

int	move_user(t_user *user, int dir)
{
	user->pos.x += dir * user->dir.x;
	user->pos.y += dir * user->dir.y;
	printf("x : %lf, y : %lf\n", user->pos.x, user->pos.y);
	return (0);
}

int	rotate_user(t_user *user, int dir)
{
	rotate_point(&user->dir, dir * M_PI/18);
	return (0);
}

// void	set_keys(t_mlx *mlx_data, t_user *user)
// {
// 	mlx_hook(mlx_data->mlx_win, 13, 0, move_user, user);
// 	mlx_hook(mlx_data->mlx_win, 0, 0, rotate_user, user);
// 	mlx_hook(mlx_data->mlx_win, 1, 0, move_user, user);
// 	mlx_hook(mlx_data->mlx_win, 2, 0, rotate_user, user);
// }

int	key_press(int keycode, t_user *user)
{
	if (keycode == 13)
		move_user(user, 1);
	else if (keycode == 0)
		rotate_user(user, 1);
	else if (keycode == 1)
		move_user(user, -1);
	else if (keycode == 2)
		rotate_user(user, -1);
	else if (keycode == 53)
		exit(0);
	return (0);
}

t_user	*set_user(double pos_x, double pos_y, double dir_x, double dir_y)
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

void test(){
	t_user	*user;
	t_info	*info;

	//-------------not here--------------------------
	info = (t_info *)malloc(sizeof(t_info));
	//-------------not here--------------------------
	init_mlx_datas(info);
	user = set_user(4.0, 1.0, 0.0, 1.0);
	info->user = user;
	//mlx_key_hook(info->mlx, key_press, &user);
	ray_casting(info);
	mlx_hook(info->mlx_win, DESTROY_NOTIFY, 0, close_window, (void *)0);
	draw_map(info->mlx, info->mlx_win, &(info->img));
	draw_user(info);
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img.img, 0, 0);
	//mlx_loop_hook(info->mlx, draw_user, &info);
	mlx_loop(info->mlx);
}
