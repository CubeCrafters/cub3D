/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inryu <inryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:09:26 by inryu             #+#    #+#             */
/*   Updated: 2024/08/01 13:54:49 by inryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC		53
# define X_EVENT_KEY 17

# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"

typedef int	t_fd;

typedef struct s_rgb{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_info{
	void		*mlx;
	void		*win;
	void		*img;
	void		*no;//t_fd		no;
	void		*so;//t_fd		so;
	void		*ea;//t_fd		ea;
	void		*we;//t_fd		we;
	t_rgb		floor;
	t_rgb		ceiling;
	char		**map;
	int			hori;
	int			vert;
}	t_info;

void	print_error(char *s);
void	read_arg(char **av, t_info *info);

#endif
