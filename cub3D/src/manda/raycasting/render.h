#ifndef RENDER_H
# define RENDER_H

#include "../../../cub3D.h"
void 	draw(t_info *info);
void calc_lineheight(t_info *info, t_render *data);
void calc_render_speed(t_info *info);
void calc_side(t_info *info, t_render *data);
long long diff_tv(struct timeval *tv1, struct timeval *tv2);
#endif