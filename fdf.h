/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:50:29 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/05 20:12:22 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line.h"
# include "MLX/mlx.h"
# include <math.h>

typedef struct s_Map
{
	int		height;
	int		width;
	int		**matrix;	
	int		scale;
	int		updown;
	int		leftright;
	float	angle;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		flag;
	int		j;
}	t_Map;

int		getheight(char *file);
int		getwidth(char *file);
int		**getmap(char *file, char **str);
void	draw(t_Map *data);
void	picture(t_Map *data);
int		which_key(int key, t_Map *data);
float	max(float a, float b);
float	mod(float a);
void	angle(float *x, float *y, int z, t_Map *data);
void	default_settings(t_Map *data);
void	rotation(t_Map *data);
void	drawrot(t_Map *data);
void	pixput(t_Map *data);
void	drawpicture(int x, int y, t_Map *data);
void	whichcolor(int z, int z1, t_Map *data);
void	setzoom(t_Map *data);
void	setposition(t_Map *data);

#endif 