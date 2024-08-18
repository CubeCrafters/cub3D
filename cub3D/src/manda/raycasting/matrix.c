#include "matrix.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//벡터 회전
void	rotate_point(t_dpoint *p, double theta)
{
	const double	tmp_x = p->x;
	const double	tmp_y = p->y;

	p->x = tmp_x * cos(theta) - tmp_y * sin(theta);
	p->y = tmp_x * sin(theta) + tmp_y * cos(theta);
}

//기존 벡터와 수직인 단위벡터 반환
t_dpoint	getpuv(t_dpoint vec)
{
	t_dpoint			unitvector;
	const double	x = vec.x;
	const double	y = vec.y;
	const double	length = sqrt(x * x + y * y);

	if (length == 0)
	{
		unitvector.x = 0;
		unitvector.y = 0;
	}
	else
	{
		unitvector.x = -y / length;
		unitvector.y = x / length;
	}
	return (unitvector);
}


t_dpoint	*init_dpoint(double x, double y){
	t_dpoint	*new_point;

	new_point = (t_dpoint *)malloc(sizeof(t_dpoint));
	new_point->x = x;
	new_point->y = y;
	return (new_point);
}


// int main(){
// 	//t_mat2	a,b;

// 	t_dpoint	*p;
// 	p = init_dpoint(5, 3);
// 	rotate_point(p, M_PI/2);
// 	printf("x = %lf, y = %lf", p->x, p->y);
// 	//a = init_mat2(1,2,3,4);
// 	//b = init_mat2(3,4,5,6);
// 	//printf("%lf",a[1][1]);
// }