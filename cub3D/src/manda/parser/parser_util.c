/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:23:28 by inryu             #+#    #+#             */
/*   Updated: 2024/08/18 13:58:17 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	cd_iscolor(int c)
{
	if (0 <= c && c <= 255)
		return (1);
	return (0);
}

void	free_strings(char **d)
{
	int	i;

	if (!d)
		return ;
	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void get_img(t_info *info, t_check *ch)
{
    int wid;
    int hei;

    info->no.img = mlx_xpm_file_to_image(info->mlx, ch->img[0], &wid, &hei);
    info->so.img = mlx_xpm_file_to_image(info->mlx, ch->img[1], &wid, &hei);
    info->ea.img = mlx_xpm_file_to_image(info->mlx, ch->img[2], &wid, &hei);
    info->we.img = mlx_xpm_file_to_image(info->mlx, ch->img[3], &wid, &hei);
    
    if (!(info->no.img) || !(info->so.img) || !(info->ea.img) || !(info->we.img))
        print_error("loading images failed");

    info->no.addr = mlx_get_data_addr(info->no.img, &info->no.bits_per_pixel, &info->no.line_length, &info->no.endian);
    info->so.addr = mlx_get_data_addr(info->so.img, &info->so.bits_per_pixel, &info->so.line_length, &info->so.endian);
    info->ea.addr = mlx_get_data_addr(info->ea.img, &info->ea.bits_per_pixel, &info->ea.line_length, &info->ea.endian);
    info->we.addr = mlx_get_data_addr(info->we.img, &info->we.bits_per_pixel, &info->we.line_length, &info->we.endian);

    if (!(info->no.addr) || !(info->so.addr) || !(info->ea.addr) || !(info->we.addr))
        print_error("getting data address failed");
    
    info->no.width = wid;
    info->no.height = hei;
    info->so.width = wid;
    info->so.height = hei;
    info->ea.width = wid;
    info->ea.height = hei;
    info->we.width = wid;
    info->we.height = hei;
}


