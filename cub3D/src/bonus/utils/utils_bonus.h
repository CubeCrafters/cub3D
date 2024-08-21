/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:25 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:43:05 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "../cub3D_bonus.h"

# define DESTROY_NOTIFY	17

int		close_window(t_info *info);
void	print_error(char *s);
int		exit_game(int key_val, t_info *data);
int		key_press(int keycode, t_info *info);
void	key_w(t_info *info);
void	key_s(t_info *info);
int		ft_strcmp(char *s1, char *s2);
void	free_strings(char **d);

#endif