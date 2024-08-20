/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 07:00:25 by sehwjang          #+#    #+#             */
/*   Updated: 2024/08/21 07:00:26 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../cub3D.h"

# define DESTROY_NOTIFY	17

int		close_window(t_info *info);
void	print_error(char *s);

void	key_w(t_info *info);
void	key_s(t_info *info);
#endif