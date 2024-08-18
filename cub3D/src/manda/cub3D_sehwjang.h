#ifndef CUB3D_H
# define CUB3D_H

#include <sys/time.h>

#define SCREEN_HEIGHT	640
#define SCREEN_WIDTH	640

#define KEY_ESC			53
#define KEY_W			13
#define KEY_A			0
#define KEY_S			1
#define KEY_D			2

typedef int	t_fd;


typedef struct s_point{
	double	x;
	double	y;
}	t_dpoint;

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_rgb{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

typedef struct s_user{
	t_dpoint	pos;
	t_dpoint	dir;
	t_dpoint	camera;
}	t_user;

typedef struct s_info{
	t_fd		no;	//void *
	t_fd		so;
	t_fd		ea;
	t_fd		we;
	t_rgb		floor;
	t_rgb		ceiling;
	//int			**map;	//char *
	int     (*map)[25];	//char *
	int			hori;
	int			vert;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_user		*user;
	double		movespeed;
	double		rotspeed;
	struct timeval time;
}	t_info;

void	init_info(t_info *info);
void draw(t_info *info);


#endif