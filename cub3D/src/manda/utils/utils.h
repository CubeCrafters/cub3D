/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:25 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/23 14:54:50 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../cub3D.h"

# define DESTROY_NOTIFY	17
# define X_EVENT_KEY	17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124

int		close_window(t_info *info);
void	print_error(char *s);
int		exit_game(int key_val, t_info *data);
int		key_press(int keycode, t_info *info);
void	key_w(t_info *info);
void	key_s(t_info *info);
void	key_a(t_info *info);
void	key_d(t_info *info);
int		ft_strcmp(char *s1, char *s2);
void	free_strings(char **d);
int		cd_atoi(char *av);

#endif
