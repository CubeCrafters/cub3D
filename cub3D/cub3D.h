#ifndef CUB3D_H
# define CUB3D_H

typedef int	t_fd;

typedef struct s_rgb{
	unsinged char	r;
	unsinged char	g;
	unsinged char	b;
}	t_rgb;

typedef struct s_info{
	t_fd		no;
	t_fd		so;
	t_fd		ea;
	t_fd		we;
	t_rgb		floor;
	t_rgb		ceiling;
	int			**map;
	int			hori;
	int			vert;
}	t_info;

#endif