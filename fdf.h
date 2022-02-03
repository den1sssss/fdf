/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:50:29 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/03 19:53:03 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "MLX/mlx.h"
# include <math.h>

typedef struct
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
}	Map;

int		getheight(char *file);
int		getwidth(char *file);
int		**getmap(char *file);
void	draw(float x, float y, float x1, float y1, Map *data);
// void	draw(Map *data);
void	picture(Map *data);
int		which_key(int key, Map *data);
float	max(float a, float b);
float	mod(float a);
void	angle(float *x, float *y, int z, Map *data);
void	default_settings(Map *data);

#endif 