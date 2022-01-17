#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
/*
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

}
*/
int **getmap(char **line)
{
	
}
int main(int argc, char **argv)
{
	int fd;
	fd=open("1.txt",O_RDONLY);
	printf("%d",getheight("1.txt"));
	return(0);
}