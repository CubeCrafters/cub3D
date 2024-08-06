/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:14:03 by inryu             #+#    #+#             */
/*   Updated: 2024/08/01 16:56:09 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	get_color(char *s, t_info *info, char c)
{
	char			**tmp;
	int				i;
	unsigned char	rgb[3];

	tmp = ft_split(s, ',');
	i = 0;
	while (tmp[i] || i < 3)
	{
		rgb[i] = ft_atoi(tmp[i]);
		if (cd_iscolor(rgb[i]) == 0)
			print_error(NULL);
		i++;
	}
	if (i != 3)
		print_error(NULL);
	if (c == 'f')
	{
		info->floor.r = rgb[0];
		info->floor.g = rgb[1];
		info->floor.b = rgb[2];
	}
	else
	{
		info->ceiling.r = rgb[0];
		info->ceiling.g = rgb[1];
		info->ceiling.b = rgb[2];
	}
	free_strings(tmp);
	return (1);
}

void	identifiers_we(char **d, t_info *info, t_check *ch)
{
	if (ft_strncmp(d[0], "WE", 2) == 0 && ch->we == 0)
	{
		info->we = mlx_xpm_file_to_image(info->mlx, ft_strtrim(d[1], "\n"), \
										&ch->wid, &ch->hei);
		if (!(info->we))
			print_error("loading image failed");
		ch->we = 1;
	}
	else if (ft_strncmp(d[0], "EA", 2) == 0 && ch->ea == 0)
	{
		info->ea = mlx_xpm_file_to_image(info->mlx, ft_strtrim(d[1], "\n"), \
										&ch->wid, &ch->hei);
		if (!(info->ea))
			print_error("loading image failed");
		ch->ea = 1;
	}
	else if (ft_strncmp(d[0], "F", 1) == 0 && ch->f == 0)
		ch->f = get_color(ft_strtrim(d[1], "\n"), info, 'f');
	else if (ft_strncmp(d[0], "C", 1) == 0 && ch->c == 0)
		ch->c = get_color(ft_strtrim(d[1], "\n"), info, 'c');
	else
		print_error("wrong element");
}

void	identifiers(char *s, t_info *info, t_check *ch)//중복들 잡을 건지, 컬러 포맷 바꿀 건지
{
	char	**d;

	d = ft_split(s, ' ');
	if (ft_strcmp(s, "\n") == 0)
		;
	else if (ft_strncmp(d[0], "NO", 2) == 0 && ch->no == 0)
	{
		info->no = mlx_xpm_file_to_image(info->mlx, ft_strtrim(d[1], "\n"), \
										&ch->wid, &ch->hei);
		if (!(info->no))
			print_error("loading image failed");
		ch->no = 1;
	}
	else if (ft_strncmp(d[0], "SO", 2) == 0 && ch->so == 0)
	{
		info->so = mlx_xpm_file_to_image(info->mlx, ft_strtrim(d[1], "\n"), \
										&ch->wid, &ch->hei);
		if (!(info->so))
			print_error("loading image failed");
		ch->so = 1;
	}
	else
		identifiers_we(d, info, ch);
	free_strings(d);
}
