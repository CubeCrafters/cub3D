/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:01:04 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:44:45 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "../cub3D_bonus.h"

void		draw(t_info *info);
void		calc_lineheight(t_info *info, t_render *data);
void		calc_render_speed(t_info *info);
void		calc_side(t_info *info, t_render *data);
void		calc_dist(t_info *info, t_render *data);
long long	diff_tv(struct timeval *tv1, struct timeval *tv2);
void		set_data(t_info *info, t_render *data, int x);
void		color_background(t_info *info);
void		set_data(t_info *info, t_render *data, int x);
#endif