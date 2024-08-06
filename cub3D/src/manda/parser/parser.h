/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:56:54 by inryu             #+#    #+#             */
/*   Updated: 2024/08/06 14:01:21 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_PARSER_H
# define CD_PARSER_H

# include <stdbool.h>
# include <stdlib.h>
# include "../../../cub3D.h"

typedef struct s_check
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	f;
	bool	c;
	bool	s;
	int		wid;
	int		hei;
}			t_check;

char	*get_next_line(int fd);
void	identifiers(char *s, t_info *info, t_check *ch);
int		cd_iscolor(int c);
void	free_strings(char **d);
int		ft_strcmp(char *s1, char *s2);
void	valid_map(char **map);

#endif
