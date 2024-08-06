#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include "../utils/utils.h"

// int	move_user(t_user *user, int dir)
// {
// 	user->pos.x += dir * user->dir.x;
// 	user->pos.y += dir * user->dir.y;
// 	printf("x : %lf, y : %lf\n", user->pos.x, user->pos.y);
// 	return (0);
// }

// int	rotate_user(t_user *user, int dir)
// {
// 	rotate_point(&user->dir, dir * M_PI/18);
// 	return (0);
// }

// void	set_keys(t_mlx *mlx_data, t_user *user)
// {
// 	mlx_hook(mlx_data->mlx_win, 13, 0, move_user, user);
// 	mlx_hook(mlx_data->mlx_win, 0, 0, rotate_user, user);
// 	mlx_hook(mlx_data->mlx_win, 1, 0, move_user, user);
// 	mlx_hook(mlx_data->mlx_win, 2, 0, rotate_user, user);
// }





void draw(t_info *info){
	ray_casting(info);
	
	mlx_put_image_to_window(info->mlx, info->mlx_win, info->img.img, 0, 0);
}

// void foo(){
// 	//timing for input and FPS counter
//     oldTime = time;
//     gettimeofday(&tv, NULL);
// 	time = tv.tv_sec;//마이크로초단위로 세는 로직 필요
//     double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
//     print(1.0 / frameTime); //FPS counter
//     redraw();
//     cls();

//     //speed modifiers
//     double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
//     double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
// 	readKeys();
//     //move forward if no wall in front of you
//     if (keyDown(SDLK_UP))
//     {
//       if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
//     }
//     //move backwards if no wall behind you
//     if (keyDown(SDLK_DOWN))
//     {
//       if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
//       if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
//     }
//     //rotate to the right
//     if (keyDown(SDLK_RIGHT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
//       dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
//       planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
//     }
//     //rotate to the left
//     if (keyDown(SDLK_LEFT))
//     {
//       //both camera direction and camera plane must be rotated
//       double oldDirX = dirX;
//       dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
//       dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
//       double oldPlaneX = planeX;
//       planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
//       planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
//     }
// }