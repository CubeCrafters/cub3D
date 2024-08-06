/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/08/01 13:37:07 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	print_error(char *s)
{
	ft_putendl_fd("Error", 2);
	if (s)
		ft_putendl_fd(s, 2);
	exit(1);
}

int	key_press(int key, t_info *data)
{
	(void)data;
	if (key == ESC)
		exit(0);
	return (0);
}

int	exit_game(int key_val, t_info *data)
{
	(void) key_val;
	(void) data;
	exit(0);
	return (0);
}

int main(int ac, char **av)
{
	t_info	info;

	if (ac != 2)
		print_error("this program takes one parameter");
	ft_bzero(&info, sizeof(t_info));
	info.mlx = mlx_init();
	if (info.mlx == NULL)
		return(1);
	read_arg(av, &info);
	info.win = mlx_new_window(info.mlx, 100, 100, "Hello world!");
	if (info.win == NULL)
		printf("!!!!!");//
	info.img = mlx_new_image(info.mlx, 100, 100);
	mlx_hook(info.win, X_EVENT_KEY, 0, &exit_game, &info);
	mlx_key_hook(info.win, key_press, &info);
	mlx_loop(info.mlx);
}
