/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:25 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 16:19:46 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../cub3D.h"

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