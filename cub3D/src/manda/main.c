/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:13:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/07/24 20:10:16 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
int main(){
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (mlx == NULL)
		return(1);
	mlx_win = mlx_new_window(mlx, 100, 100, "Hello world!");
	if (mlx_win == NULL)
		printf("!!!!!");
	mlx_loop(mlx);
}