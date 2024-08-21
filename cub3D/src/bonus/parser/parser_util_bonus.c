/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:23:28 by inryu             #+#    #+#             */
/*   Updated: 2024/08/21 16:45:37 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"
#include "../utils/utils_bonus.h"

int	cd_iscolor(int c)
{
	if (0 <= c && c <= 255)
		return (1);
	return (0);
}

static void	file_to_img(t_info *info, t_check *ch, int *wid, int *hei)
{
	info->no.img = mlx_xpm_file_to_image(info->mlx, ch->img[0], wid, hei);
	info->no.width = *wid;
	info->no.height = *hei;
	info->so.img = mlx_xpm_file_to_image(info->mlx, ch->img[1], wid, hei);
	info->so.width = *wid;
	info->so.height = *hei;
	info->ea.img = mlx_xpm_file_to_image(info->mlx, ch->img[2], wid, hei);
	info->ea.width = *wid;
	info->ea.height = *hei;
	info->we.img = mlx_xpm_file_to_image(info->mlx, ch->img[3], wid, hei);
	info->we.width = *wid;
	info->we.height = *hei;
	if (!(info->no.img) || !(info->so.img) \
		|| !(info->ea.img) || !(info->we.img))
		print_error("loading images failed");
}

static void	get_data_addr(t_info *info)
{
	info->no.addr = mlx_get_data_addr(info->no.img, &info->no.bits_per_pixel, \
									&info->no.line_length, &info->no.endian);
	info->so.addr = mlx_get_data_addr(info->so.img, &info->so.bits_per_pixel, \
									&info->so.line_length, &info->so.endian);
	info->ea.addr = mlx_get_data_addr(info->ea.img, &info->ea.bits_per_pixel, \
									&info->ea.line_length, &info->ea.endian);
	info->we.addr = mlx_get_data_addr(info->we.img, &info->we.bits_per_pixel, \
									&info->we.line_length, &info->we.endian);
	if (!(info->no.addr) || !(info->so.addr) \
		|| !(info->ea.addr) || !(info->we.addr))
		print_error("getting data address failed");
}

void	get_img(t_info *info, t_check *ch)
{
	int	wid;
	int	hei;

	file_to_img(info, ch, &wid, &hei);
	get_data_addr(info);
}
