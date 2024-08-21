/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:56:54 by inryu             #+#    #+#             */
/*   Updated: 2024/08/21 16:45:49 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# include <stdbool.h>
# include <stdlib.h>
# include "../cub3D_bonus.h"

typedef struct s_check
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	f;
	bool	c;
	int		s;
	char	*img[4];
}			t_check;

char	*get_next_line(int fd);
void	identifiers(char *s, t_info *info, t_check *ch);
int		cd_iscolor(int c);
void	free_strings(char **d);
int		ft_strcmp(char *s1, char *s2);
void	get_img(t_info *info, t_check *ch);
void	valid_info(t_info *info, t_check *ch);

#endif
