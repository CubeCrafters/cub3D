#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include "../cub3D.h"
#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

static void verLine_tex(t_info *info, int x, int drawStart, int drawEnd, double wallX, int side, t_data *texture)
{
    int texWidth = texture->width;
    int texHeight = texture->height;

    int texX = (int)(wallX * (double)texWidth);
    if ((side == 0 && info->user->dir.x > 0) || (side == 2 && info->user->dir.y < 0))
        texX = texWidth - texX - 1;

    double step = 1.0 * texHeight / (drawEnd - drawStart);
    double texPos = (drawStart - SCREEN_HEIGHT / 2 + (drawEnd - drawStart) / 2) * step;

    for (int y = drawStart; y < drawEnd; y++)
    {
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;

        char *pixel = texture->addr + (texY * texture->line_length + texX * (texture->bits_per_pixel / 8));
        int color = *(unsigned int *)pixel;

        if (side == 1 || side == 2)
            color = (color >> 1) & 0x7F7F7F;

        my_mlx_pixel_put(&info->img, x, y, color);
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

    t_point plane = getpuv(info->user->dir);
    double planeX = plane.x;
    double planeY = plane.y;

    double rayDirX;
    double rayDirY;
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
        rayDirX = dirX + planeX * cameraX;
        rayDirY = dirY + planeY * cameraX;

        int mapX = (int)posX;
        int mapY = (int)posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);

        double perpWallDist;

        int stepX;
        int stepY;
        int hit = 0;
        int side;

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

        while (hit == 0)
        {
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
            if (info->map[mapX][mapY] == '1')
                hit = 1;
        }

        if (side <= 1)
            perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
        if (drawEnd >= SCREEN_HEIGHT)
            drawEnd = SCREEN_HEIGHT - 1;

        double wallX;
        if (side <= 1)
            wallX = posY + perpWallDist * rayDirY;
        else
            wallX = posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        t_data *texture;
        if (side == 1)
            texture = &info->ea;
        else if (side == 2)
            texture = &info->we;
        else if (side == 3)
            texture = &info->so;
        else
            texture = &info->no;

        verLine_tex(info, x, drawStart, drawEnd, wallX, side, texture);
    }
    
    oldtime = info->time;
    gettimeofday(&info->time, NULL);
    double frameTime = diff_tv(&info->time, &oldtime) / 1000000.0;
    info->movespeed = frameTime * 5.0;
    info->rotspeed = frameTime * 3.0;
}
