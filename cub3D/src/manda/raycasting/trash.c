// void	draw_wall(int x, int y,t_data *data){
// 	for(int i = (y)*50; i<(y+1)*50;i++){
// 		for(int j = (x)*50; j<(x+1)*50;j++){
// 			my_mlx_pixel_put(data, i,j,255);
// 		}
// 	}
// }

// void	draw_map(void *mlx, void *mlx_win, t_data *img){
	
// 	for(int i = 0 ; i<12; i++){
// 		for(int j = 0; j< 25; j++){
// 			if (maze[i][j] == 1)
// 				draw_wall(i,j,img);
// 		}
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
// }


// int	draw_user(t_info *info)
// {
// 	double	grad;

// 	t_user	user = *info->user;
// 	double my_x = user.pos.x * 50 + 25;
// 	double my_y = user.pos.y * 50 + 25;
// 	my_mlx_pixel_put(&info->img, my_x, my_y, 0xFF0000);
	
// 	if(user.dir.x == 0){

// 	}
// 	else{
// 		rotate_point(&user.dir, -M_PI/6);
// 		for(int j = 0; j <60;j++ ){
// 			grad = user.dir.y / user.dir.x;
// 			for (int i = my_x; i< 25 * 50;i++)
// 			{
// 				if (info->map[(int)(grad * (i - my_x) + my_y) / 50][i / 50] == 1)
// 				{	
// 					my_mlx_pixel_put(&info->img, i, (grad * (i - my_x) + my_y), 0xFFFFFF);
// 					break ;
// 				}
// 				my_mlx_pixel_put(&info->img, i, grad * (i - my_x) + my_y, 0xFF0000);
// 			}
// 			rotate_point(&user.dir, M_PI/180);
// 		}
// 	}
// 	return (0);
// }