#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

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
	char	**arr;

	len = 0;
	arr = ft_split(file, ' ');
	while (arr[len])
		len++;
	return (len);
}

int **getmap(char *file)
{
	int	w;
	int	h;
	int	i;
	int j;
	int	**map;
	char **str;

	i = 0;
	h = getheight(file);
	w = getwidth(&file[0]);
	map = (int **)malloc(sizeof(int*) * h);
	while (i < h)
	{
		map[i] = (int *)malloc(sizeof(int) * w);
		str = ft_split((get_next_line(file[i])), ' ');
		j = 0;
		while (str[j])
		{
			map[i][j] = ft_atoi(str[j]);
			j++;
		}
		i++;
	}
	return (map);
}
int main(int argc, char **argv)
{
	int **matrix;
	int a =0;
	int b =0;
	int fd = open("1.txt", O_RDONLY);
	int i=getheight("1.txt");
	int j=getwidth("1.txt");
	argc = 0;
	while(a<i)
	{
		b=0;
		while(b<j)
		{
			printf("%d ",matrix[i][j]);
			b++;
		}
		printf(" ");
		a++;
	}	
}