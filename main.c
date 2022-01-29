#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "MLX/mlx.h"

int getheight(char *file)
{
	int height;
	int fd;
	char *str;

	height = 0;
	str=NULL;
	fd=open(file,O_RDONLY);
	while((str=get_next_line(fd))!= NULL)
	{
		height++;
		free(str);
	}
	close(fd);
	return(height);
}
int getwidth(char *file)
{
	int		len;
	char	*arr;
	int fd;

	len = 0;
	fd=open(file,O_RDONLY);
	arr = get_next_line(fd);
	int i;
	int words;

	words = 0;
	i = 0;
	while (arr[i])
	{
		while (arr[i] == ' ' && arr[i])
			i++;
		if (arr[i])
			words++;
		while (arr[i] != ' ' && arr[i])
			i++;
	}
	close(fd);
	return (words);
	
}
// int		width(char const *str, char c)
// {
// 	int i;
// 	int words;

// 	words = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == c && str[i])
// 			i++;
// 		if (str[i])
// 			words++;
// 		while (str[i] != c && str[i])
// 			i++;
// 	}
// 	return (words);
// }
// int *mallocinie(int **m, int i,)
// {

// }
int **getmap(char *file)
{
	int	w;
	int	h;
	int	i;
	int j;
	int fd;
	int	**map;
	char **str;
	int *massiv;

	fd = open(file, O_RDONLY);
	i = 0;
	h = getheight(file);
	w = getwidth(file);
	map = (int **)malloc(sizeof(int*) * h);
	while (i < h)
	{
		map[i] = (int *)malloc(sizeof(int) * w);
		str = ft_split(get_next_line(fd), ' ');//файл итый не катит=(((////////////////
		j = 0;
		
		massiv = map[i];
		while (str[j])
		{
			massiv[j] = ft_atoi(str[j]);
			j++;
		}
		i++;
	}
	return (map);
}
float min(float a, float b)
{
	if (a<b)
		return a;
	else 
		return b;
}
float max(float a, float b)
{
	if (a<b)
		return b;
	else 
		return a;
}

float mod(float a)
{
	if(a<0)
		return(-a);
	else
		return (a);
}

void angle(float *x,float *y, int z)
{
	float temp_x;
	float temp_y;
		printf("%f [ANGLE] %f\n",*x,*y);
		printf("\n");
	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.8) ;
	*y = (temp_x + temp_y) * sin(0.8) - z;
	// printf("%d\n%d\n",*x,*y);
}


void Draw(float x, float y, float x1, float y1, Map *data)
{
	float xx;
	float yy;
	int maximum;
	int z;
	int z1;


	// xx=x1 -x;
	// yy=y1-y;


	z=data->matrix[(int)y][(int)x];
	z1=data->matrix[(int)y1][(int)x1];

	// x*=700/max(data->height,data->width);
	// x1*=700/max(data->height,data->width);
	// y*=700/max(data->height,data->width);
	// y1*=700/max(data->height,data->width);

		printf("%f [draw] %f\n",x,y);
	 x*=30;
	 x1*=30;
	 y*=30;
	 y1*=30;
	
	//data->color =(z)? 0x89fe05 : 0xd51ffb;

	if(z>0 || z1 > 0)
		data->color= 0x89fe05;
	else	
		data->color=0xd51ffb;

	printf("%f [draw] %f\n",x,y);

	xx=x1 -x;
	yy=y1-y;



	x+=350;
	y+=350;
	x1+=350;
	y1+=350;

	// angle(&x,&y,z); //suka
	// angle(&x1,&y1,z1);

	maximum=max(mod(xx),mod(yy));
	xx /= maximum;
	yy /= maximum;
	while((int)(x-x1) || (int)(y-y1) )
	{
		// angle(&x,&y,z);
		// angle(&x1,&y1,z1);
		mlx_pixel_put(data->mlx_ptr,data->win_ptr,x,y,data->color);
		x+=xx;
		y+=yy;
	}
}

void Picture (Map *data)
{
	int x;
	int y;

	// y =0;
	// while(y<data->height-1)
	// {
	// 	x=0;
	// 	while(x<data->width+1)
	// 	{
	// 		if(x<data->width-1)
	// 			Draw(x,y,x+1,y,data);
	// 		if(y<data->height+1)
	// 			Draw(x,y,x,y+1,data);
	// 		x++;
	// 	}
	// 	y++;
	// }

	// int x;
	// int y;

	y =0;
	while(y<data->height)
	{
		x=0;
		while(x<data->width)
		{
			if(x<data->width-1)
				Draw(x,y,x+1,y,data);
			if(y<data->height-1)
				Draw(x,y,x,y+1,data);
			x++;
		}
		y++;
	}
}
int key(int a,void *data)
{
	printf("%d",a);
	return (0);
}
int main(int argc, char **argv)
{
	
	// int **matrix;
	// int a =0;
	// int b =0;
	// int fd = open("1.txt", O_RDONLY);
	// int i=getheight("1.txt");
	// int j=width("1.txt",' ');
	// argc = 0;
	// printf("%d\n\n",i);
	// printf("%d",j);
	// while(a<i)
	// {
	// 	b=0;
	// 	while(b<j)
	// 	{
	// 		printf("%d ",matrix[i][j]);
	// 		b++;
	// 	}
	// 	printf(" ");
	// 	a++;
	//
	int **kek;
	int	i;
	int	j;
	int w;
	int h;

	kek=getmap("42.fdf");
	i = 0;
	h = getheight("42.fdf");
	w = getwidth("42.fdf");
	printf("%d\n",h);
	printf("%d\n",w);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			printf("%2d ", kek[i][j]);
		printf("\n");
	}

	Map data;
	data=*(Map *)malloc(sizeof(Map));
	data.matrix=kek;
	data.height=h;
	data.width=w;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "FDF");



	// Draw(10,10,600,300,&data);
	Picture(&data);

	mlx_key_hook(data.win_ptr, key, NULL);
	mlx_loop(data.mlx_ptr);



}