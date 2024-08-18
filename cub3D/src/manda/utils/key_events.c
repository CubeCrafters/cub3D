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
