#ifndef MATRIX_H
# define MATRIX_H

#include "../../../cub3D.h"

void 	test();
void	rotate_point(t_point *p, double theta);
t_point	getpuv(t_point vec);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void ray_casting(t_info *info);
#endif