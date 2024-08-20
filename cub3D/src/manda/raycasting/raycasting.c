#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "../cub3D.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

static void	verLine(t_info *info, int x, int drawStart, int drawEnd, int color){
	for(int i = drawStart; i<= drawEnd; i++)
	{
		my_mlx_pixel_put(&info->img, x, i, color);
	}
}

long long	diff_tv(struct timeval *tv1, struct timeval	*tv2)
{
	long long	sec_diff;
	long long	usec_diff;

	sec_diff = tv1->tv_sec - tv2->tv_sec;
	usec_diff = tv1->tv_usec - tv2->tv_usec;
	return (sec_diff * 1000000 + usec_diff);
}

void ray_casting(t_info *info)
{
	struct timeval oldtime;

	double posX = info->user->pos.x;
	double posY = info->user->pos.y;
	double dirX = info->user->dir.x;
	double dirY = info->user->dir.y;

	t_dpoint plane = getpuv(info->user->dir);
	double planeX = plane.x;
	double planeY = plane.y;

	double rayDirX;
	double rayDirY;
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		// calculate ray position and direction
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; // x-coordinate in camera space
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		// which box of the map we're in
		int mapX = (int)posX;
		int mapY = (int)posY;

		// length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		// length of ray from one x or y-side to next x or y-side
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);

		double perpWallDist;

		// what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; // was there a wall hit?
		int side;	 // was a NS or a EW wall hit?
		// calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				if (rayDirX > 0)
					side = 0;
				else
					side = 1;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				if (rayDirY > 0)
					side = 2;
				else
					side = 3;
			}
			// Check if ray has hit a wall
			if (info->map[mapX][mapY] == '1')
				hit = 1;
		}
		// Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (side <= 1)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		// Calculate height of line to draw on screen
		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		int color = 0x0000ff;
		if (side == 1)
			color = 0x0ffff0;
		else if (side == 2)
			color = 0xff0000;
		else if (side == 3)
			color = 0x00ff00;
		verLine(info, x, drawStart, drawEnd, color);
	}
	oldtime = info->time;
	gettimeofday(&info->time, NULL);
    double frameTime = diff_tv(&info->time, &oldtime) / 1000000.0; //frameTime is the time this frame has taken, in seconds
    //printf("%lf\n",frameTime); //FPS counter
    // redraw();
    // cls();

    //speed modifiers
    info->movespeed = frameTime * 5.0; //the constant value is in squares/second
    info->rotspeed = frameTime * 3.0;
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
