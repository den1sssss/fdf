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
int		width(char const *str, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}
// int *mallocinie(int **m, int i,)
// {

// }
int **getmap(char *file)
{
	int	w;
	int	h;
	int	i;
	int j;
	int	**map;
	char **str;
	int *massiv;

	printf("kej");
	i = 0;
	h = getheight(file);
	w = h;
	map = (int **)malloc(sizeof(int*) * h);
	while (i < h)
	{
		printf("[%c]",file[i]);
		map[i] = (int *)malloc(sizeof(int) * w);
		str = ft_split((get_next_line(file[i])), ' ');
		j = 0;
		
		// massiv = map[i];
		// while (str[j])
		// {
		// 	massiv[j] = ft_atoi(str[j]);
		// 	j++;
		// }
		i++;
	}
	return (map);
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
	printf("hello"); 
	int **kek;

	kek=getmap("1.txt");
	return(0);
}