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

void default_settings(Map *data)
{
	data->updown=100;
	data->leftright=-100;
	data->scale=700/max(data->height,data->width);
	data->angle=0.523599;
}
 void Angle(float *x,float *y, int z,Map *data)
{
	float temp_x;
	float temp_y; 
		// printf("%f [before] %f\n",*x,*y);
		// printf("\n");
	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(data->angle) ;
	*y = (temp_x + temp_y) * sin(data->angle) - z;

	// 	*x = (temp_x - temp_y) * cos(0) ;
	// *y = (temp_x + temp_y) * sin(0) - z;
	// printf("%f [after] %f\n",*x,*y);

	// 	*x = (temp_x - temp_y) * cos(0.8) ;
	// *y = (temp_x + temp_y) * sin(0.8) - z;

	// 	printf("%f [ANGLE] %f\n",*x,*y);
	// 	printf("\n");

	// *x = (*x - *y) * cos(0.523599) ;
	// *y = (*x + *y) * sin(0.523599) - z;
}


void Draw(float x, float y, float x1, float y1, Map *data)
{
	float xx;
	float yy;
	float maximum;
	int z;
	int z1;


	// xx=x1 -x;
	// yy=y1-y;
	// printf("xx= %f  [draw] yy = %f\n",xx,yy);


	z=data->matrix[(int)y][(int)x];
	z1=data->matrix[(int)y1][(int)x1];

	// x*=700/max(data->height,data->width);
	// x1*=700/max(data->height,data->width);
	// y*=700/max(data->height,data->width);
	// y1*=700/max(data->height,data->width);

	x*=data->scale;
	x1*=data->scale;
	y*=data->scale;
	y1*=data->scale;

	// printf("%f [draw] %f\n",x,y);
	//  x*=30;
	//  x1*=30;
	//  y*=30;
	//  y1*=30;
	
	//data->color =(z)? 0x89fe05 : 0xd51ffb;

	// if(z>0 || z1 > 0)
	// 	data->color= 0xff0000;
	// else	
	// 	data->color=0xffffff;


	// xx=x1 -x;
	// yy=y1-y;
	// printf("%f=xx\n",xx);
	// printf("%f=yy\n",yy);


	// x+=500;
	// y+=100;
	// x1+=500;
	// y1+=100;



	// x+=350;
	// y+=350;
	// x1+=350;
	// y1+=350;

	// printf("%f [before] %f\n",x,y);
	Angle(&x,&y,z, data); //suka
	// printf("%f [after] %f\n",x,y);

	// printf("%f [1before] %f\n",x1,y1);
	Angle(&x1,&y1,z1 , data);
	// printf("%f [1after] %f\n",x1,y1);

	xx=x1 -x;
	yy=y1-y;
	maximum=max(mod(xx),mod(yy));
	xx /= maximum;

	// printf("%f=xx1\n",xx);

	yy /= maximum;

	// default_settings(data);

	x+=data->leftright;
	y+=data->updown;
	x1+=data->leftright;
	y+=data->updown;

	// 	x=data->updown;
	// y=data->leftright;
	// x1=data->updown;
	// y=data->leftright;


	// x+=500;
	// y+=100;
	// x1+=500;
	// y1+=100;
	// printf("%f %f\n",x,y);
	// printf("%f=yy1\n",yy);
	// printf("%f [xx][yy] %f\n",xx,yy);

	// if(z<0 && z1<0)	
	// 	data->color=0x0000FF;// blue water
	// else if(z >0 && z1<10)
	// 	data->color = 0x00FF00; //green gras
	// else if(z>=10 && z1 >= 10)
	// 	data->color= 0xFFFFFF;


	if(z>0 || z1 > 0)
		data->color= 0xFF0000;
	else	
		data->color=0xFFFFFF;//A020F0;
	while((int)(x-x1) && (int)(y-y1) )
	{
		// angle(&x,&y,z);
		// angle(&x1,&y1,z1);
		mlx_pixel_put(data->mlx_ptr,data->win_ptr,x,y,data->color);
		x+=xx;
		// printf("%f = x\n",x);
		// 	printf("%f=y\n",y);
		y+=yy;
		// printf("kek\n");
		if( x<0 || y<0)
			break;
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
			{
				// printf("draw x\n\n");
				Draw(x,y,x+1,y,data);
				// printf("\n\n");
			}
			if(y<data->height-1)
			{
				// printf("draw y\n\n");
				Draw(x,y,x,y+1,data);
				// printf("\n\n");
			}
			x++;
		}
		y++;
	}
	printf("\nleftright %d\n",data->leftright);
	printf("updown %d\n\n",data->updown);
}
void hehehe(Map *data)
{
	int i;

	i=0;

	while(i<100)
	{
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		data->angle+=0.2;
		Picture(data);
		mlx_clear_window(data->mlx_ptr,data->win_ptr);
		i++;
	}
}
int which_key(int key,Map *data)
{
	// data->leftright=500;
	// data->updown=500;
	printf("button %d",key);
	if(key ==123)
		data->leftright-=100;
	if(key==124)
		data->leftright+=100;
	if(key ==125)
		data->updown+=100;
	if(key ==126)
		data->updown-=100;
	if(key == 27) // -
		data->scale/=1.3;
	if (key ==24) //+
		data->scale*=1.3;
	if(key == 49 && 1) // moron
	{
			data->angle+=0.1;
	}
	mlx_clear_window(data->mlx_ptr,data->win_ptr);
	Picture(data);
	// printf("yessir\n");
	return (0);
}
int main(void)
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
	int w;
	int h;

	// kek=getmap("elem2.fdf");
	// h = getheight("elem2.fdf");
	// w = getwidth("elem2.fdf");

	kek=getmap("42.fdf");
	h = getheight("42.fdf");
	w = getwidth("42.fdf");

	// 	kek=getmap("pyra.fdf");
	// h = getheight("pyra.fdf");
	// w = getwidth("pyra.fdf");
	
	

	i=0;
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


	default_settings(&data);
	// Draw(10,10,600,300,&data);
	Picture(&data);

	mlx_key_hook(data.win_ptr, which_key, &data);
	mlx_do_sync(data.mlx_ptr);
	mlx_loop(data.mlx_ptr);



}