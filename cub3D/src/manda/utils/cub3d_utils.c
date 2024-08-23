/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:08 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/23 14:59:50 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
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

int	cd_atoi(char *av)
{
	int			i;
	long long	res;

	res = 0;
	i = 0;
	if (av[i] == '-' || av[i] == '+')
	{
		if (av[i++] == '-')
			return (-1);
	}
	if ('0' <= av[i] && av[i] <= '9')
	{
		while ('0' <= av[i] && av[i] <= '9')
		{
			res = res * 10 + (av[i] - '0');
			if (res > 2147483647)
				return (-1);
			i++;
		}
		if (av[i] != '\0')
			return (-1);
	}
	else
		return (-1);
	return (res);
}
