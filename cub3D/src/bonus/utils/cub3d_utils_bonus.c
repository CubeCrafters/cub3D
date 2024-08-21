/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:08 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:43:42 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include "libft.h"

void	print_error(char *s)
{
	ft_putendl_fd("Error", 2);
	if (s)
		ft_putendl_fd(s, 2);
	exit(1);
}

int	exit_game(int key_val, t_info *data)
{
	(void) key_val;
	(void) data;
	exit(0);
	return (0);
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
