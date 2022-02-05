/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:56:56 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/05 17:05:52 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	drawrot(Map *data) 
{
	float	xx;
	float	yy;
	float	maximum;
	int		z;
	int		z1;

	z = data->matrix[(int)data->y][(int)data->x];
	z1 = data->matrix[(int)data->y1][(int)data->x1];
	data->x *= data->scale;
	data->x1 *= data->scale;
	data->y *= data->scale;
	data->y1 *= data->scale;
	xx = data->x1 - data->x;
	yy = data->y1 - data->y;
	maximum = max(mod(xx), mod(yy));
	xx /= maximum;
	yy /= maximum;
	data->x += data->leftright;
	data->y += data->updown;
	data->x1 += data->leftright;
	data->y1 += data->updown;
	if (z > 0 || z1 > 0)
		data->color = 0xFF0000;
	else
		data->color = 0xFFFFFF;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->color);
		data->x += xx;
		data->y += yy;
		if (data->x < 0 || data->y < 0)
			break ;
	}
}