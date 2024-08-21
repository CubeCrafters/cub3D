/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_info_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 16:57:27 by inryu             #+#    #+#             */
/*   Updated: 2024/08/21 16:45:42 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	check_sides(int i, int j, t_info *info)
{
	char	**map;

	if (i == 0 || i == info->vert - 1)
		return (0);
	else if (j == 0 || j == info->hori - 1)
		return (0);
	map = info->map;
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ')
		return (0);
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (0);
	if (map[i - 1][j - 1] == ' ' || map[i + 1][j + 1] == ' ')
		return (0);
	if (map[i + 1][j - 1] == ' ' || map[i - 1][j + 1] == ' ')
		return (0);
	return (1);
}

int	check_cell(int i, int j, t_info *info, t_check *ch)
{
	char	c;
	t_user	*user;

	c = info->map[i][j];
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		user = set_user(i, j, c);
		info->user = user;
		(ch->s)++;
		return (check_sides(i, j, info));
	}
	else if (c == '0')
		return (check_sides(i, j, info));
	else if (c != ' ' && c != '1')
		print_error("there is a legend that is not included in the PDF");
	return (1);
}

int	valid_map(t_info *info, t_check *ch)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->vert)
	{
		j = 0;
		while (j < info->hori)
		{
			if (check_cell(i, j, info, ch) == 0)
				return (0);
			j++;
		}
		i++;
	}
	if (ch->s != 1)
		print_error("Map must contain 1 starting position");
	return (1);
}

void	check_info(t_info *info, t_check *ch)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 4)
		{
			if (ft_strcmp(ch->img[i], ch->img[j]) == 0)
				print_error("The wall texture is duplicated");
			j++;
		}
		i++;
	}
	get_img(info, ch);
	if (info->ceiling == info->floor)
		print_error("The color is duplicated");
}

void	valid_info(t_info *info, t_check *ch)
{
	check_info(info, ch);
	if (valid_map(info, ch) == 0)
		print_error("Map must be surrounded by walls");
}
