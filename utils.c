/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:40:56 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/05 19:55:36 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

float	mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	default_settings(t_Map *data)
{
	data->updown = 100;
	data->leftright = -100;
	data->scale = 700 / max(data->height, data->width);
	data->angle = 0.523599;
	data->flag = 0;
}

void	angle(float *x, float *y, int z, t_Map *data)
{
	float	temp_x;
	float	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(data->angle);
	*y = (temp_x + temp_y) * sin(data->angle) - z;
}

void	pixput(t_Map *data)
{
	mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->color);
}
