/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehwjang <sehwjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:09:26 by inryu             #+#    #+#             */
/*   Updated: 2024/08/18 13:47:23 by sehwjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_HEIGHT	640
# define SCREEN_WIDTH	640

# define X_EVENT_KEY	17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"
# include <sys/time.h>
// typedef int	t_fd;

// typedef struct s_rgb{
// 	unsigned char	r;
// 	unsigned char	g;
// 	unsigned char	b;
// }	t_rgb;

typedef struct s_point{
	double	x;
	double	y;
}	t_point;

typedef struct s_user{
	t_point	pos;
	t_point	dir;
	t_point	camera;
}	t_user;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;      // 텍스처 이미지의 너비
	int		height;     // 텍스처 이미지의 높이
}	t_data;

// typedef struct s_info{
// 	void		*mlx;
// 	void		*win;
// 	t_data		img;
// 	void		*no;//t_fd		no;
// 	void		*so;//t_fd		so;
// 	void		*ea;//t_fd		ea;
// 	void		*we;//t_fd		we;
// 	int			floor;// t_rgb		floor;
// 	int			ceiling;// t_rgb		ceiling;
// 	char		**map;
// 	int			hori;
// 	int			vert;
// 	t_user		*user;
// 	double		movespeed;
// 	double		rotspeed;
// 	struct timeval time;
// }	t_info;

typedef struct s_info {
    void *mlx;
    void *win;
    t_data img;
    t_data no;       // void* 대신 t_data 사용
    t_data so;
    t_data ea;
    t_data we;
    int floor;
    int ceiling;
    char **map;
    int hori;
    int vert;
    t_user *user;
    double movespeed;
    double rotspeed;
    struct timeval time;
} t_info;

void	print_error(char *s);
void	read_arg(char **av, t_info *info);
void	init_info(t_info *info);
void 	draw(t_info *info);

t_user	*set_user(double pos_x, double pos_y, char dir);
#endif
