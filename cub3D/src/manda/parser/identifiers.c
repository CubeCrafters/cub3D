/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:14:03 by inryu             #+#    #+#             */
/*   Updated: 2024/08/18 12:22:50 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	get_color(char *s, t_info *info, char c)//컬러 포맷 바꾸기, 컬러 안 같게 막기
{
	char	**tmp;
	int		i;
	int		rgb[3];

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
		info->floor = rgb[0] * 256 * 256 + rgb[1] * 256 + rgb[2];
	else
		info->ceiling = rgb[0] * 256 * 256 + rgb[1] * 256 + rgb[2];
	free_strings(tmp);
	return (1);
}

void	identifiers_we(char **d, t_info *info, t_check *ch, int i)
{
	if (ft_strncmp(d[0], "WE", 2) == 0 && ch->we == 0 && i == 2)
	{
		ch->img[2] = ft_strtrim(d[1], "\n");
		ch->we = 1;
	}
	else if (ft_strncmp(d[0], "EA", 2) == 0 && ch->ea == 0 && i == 2)
	{
		ch->img[3] = ft_strtrim(d[1], "\n");
		ch->ea = 1;
	}
	else if (ft_strncmp(d[0], "F", 1) == 0 && ch->f == 0 && i == 2)
		ch->f = get_color(ft_strtrim(d[1], "\n"), info, 'f');
	else if (ft_strncmp(d[0], "C", 1) == 0 && ch->c == 0 && i == 2)
		ch->c = get_color(ft_strtrim(d[1], "\n"), info, 'c');
	else
		print_error("wrong element(s)");
}

void	identifiers(char *s, t_info *info, t_check *ch)//같은 파일 여러번 읽으려고 하면 막기
{
	char	**d;
	int		i;

	d = ft_split(s, ' ');
	i = 0;
	while (d[i])
		i++;
	if (ft_strcmp(s, "\n") == 0)
		;
	else if (ft_strncmp(d[0], "NO", 2) == 0 && ch->no == 0 && i == 2)
	{
		ch->img[0] = ft_strtrim(d[1], "\n");
		ch->no = 1;
	}
	else if (ft_strncmp(d[0], "SO", 2) == 0 && ch->so == 0 && i == 2)
	{
		ch->img[1] = ft_strtrim(d[1], "\n");
		ch->so = 1;
	}
	else
		identifiers_we(d, info, ch, i);
	free_strings(d);
}
