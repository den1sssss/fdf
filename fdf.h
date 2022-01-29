#ifndef FDF_H
# define FDF_H

typedef struct 
{
	int height;
	int width;
	int **matrix;	
	int scale;

	int color;
	void	*mlx_ptr;
	void	*win_ptr;
}   Map;

# include "libft/libft.h"
# include <math.h>
# include "MLX/mlx.h"

#endif 