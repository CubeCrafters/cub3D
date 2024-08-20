/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:16 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 07:00:17 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	key_w(t_info *info)
{
	if (info->map[(int)(info->user->pos.x \
						+ info->movespeed * info->user->dir.x)] \
				[(int)(info->user->pos.y + info->movespeed \
						* info->user->dir.y)] != '1')
	{
		info->user->pos.x += info->movespeed * info->user->dir.x;
		info->user->pos.y += info->movespeed * info->user->dir.y;
	}
}

void	key_s(t_info *info)
{
	if (info->map[(int)(info->user->pos.x - \
						- info->movespeed * info->user->dir.x)] \
				[(int)(info->user->pos.y - info->movespeed \
						* info->user->dir.y)] != '1')
	{
		info->user->pos.x -= info->movespeed * info->user->dir.x;
		info->user->pos.y -= info->movespeed * info->user->dir.y;
	}
}
