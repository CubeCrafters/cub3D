#ifndef CUB3D_H
# define CUB3D_H

#define SCREEN_HEIGHT	640
#define SCREEN_WIDTH	640


typedef int	t_fd;


typedef struct s_point{
	double	x;
	double	y;
}	t_point;

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
	t_point	pos;
	t_point	dir;
	t_point	camera;
}	t_user;

typedef struct s_info{
	t_fd		no;
	t_fd		so;
	t_fd		ea;
	t_fd		we;
	t_rgb		floor;
	t_rgb		ceiling;
	//int			**map;
	int     (*map)[25];
	int			hori;
	int			vert;
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_user		*user;
}	t_info;





#endif