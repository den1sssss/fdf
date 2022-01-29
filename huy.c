#include <stdio.h>
typedef struct s_dot 
{
	int x;
	int y;
	int z;
	struct t_dot *next;
}   			t_dot;
int main(int argc, char **argv)
{
	t_dot **map;
	map = (t_dot **)malloc(sizeof(t_dot) * width * height);
	int a =132;
	int b =1543;
	map->matrix[0][0]=a;
	printf("%d",map->matrix[0][0]);
}
