/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:01:48 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:44:33 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_BONUS_H
# define MATRIX_BONUS_H

# include "../cub3D_bonus.h"

void		rotate_point(t_dpoint *p, double theta);
t_dpoint	getpuv(t_dpoint vec);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		ray_casting(t_info *info);
#endif