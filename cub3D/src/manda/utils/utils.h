#ifndef UTILS_H
# define UTILS_H

# include "../cub3D.h"

# define DESTROY_NOTIFY	17

int		close_window(t_info *info);
void	print_error(char *s);

void	key_w(t_info *info);
void	key_s(t_info *info);
#endif