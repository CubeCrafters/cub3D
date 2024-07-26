#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
void	rotate_point(t_point *p, double theta)
{
	const double	tmp_x = p->x;
	const double	tmp_y = p->y;

	p->x = tmp_x * cos(theta) - tmp_y * sin(theta);
	p->y = tmp_x * sin(theta) + tmp_y * cos(theta);
}

// t_mat2	init_mat2(double a1, double a2, double b1, double b2){
// 	t_mat2	ret_mat;

// 	ret_mat = (double **)malloc(sizeof)
// 	ret_mat[0][0] = a1;
// 	ret_mat[0][1] = a2;
// 	ret_mat[1][0] = b1;
// 	ret_mat[1][1] = b2;
// 	return (ret_mat);
// }

t_point	*init_point(double x, double y){
	t_point	*new_point;

	new_point = (t_point *)malloc(sizeof(t_point));
	new_point->x = x;
	new_point->y = y;
	return (new_point);
}


// int main(){
// 	//t_mat2	a,b;

// 	t_point	*p;
// 	p = init_point(5, 3);
// 	rotate_point(p, M_PI/2);
// 	printf("x = %lf, y = %lf", p->x, p->y);
// 	//a = init_mat2(1,2,3,4);
// 	//b = init_mat2(3,4,5,6);
// 	//printf("%lf",a[1][1]);
// }