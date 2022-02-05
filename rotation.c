/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:56:56 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/05 19:55:08 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawrot(t_Map *data)
{
	float	xx;
	float	yy;
	float	maximum;
	int		z;
	int		z1;

	z = data->matrix[(int)data->y][(int)data->x];
	z1 = data->matrix[(int)data->y1][(int)data->x1];
	setzoom(data);
	xx = data->x1 - data->x;
	yy = data->y1 - data->y;
	maximum = max(mod(xx), mod(yy));
	xx /= maximum;
	yy /= maximum;
	setposition(data);
	whichcolor(z, z1, data);
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		pixput(data);
		data->x += xx;
		data->y += yy;
	}
}

void	rotationdraw(t_Map *data, int x, int y)
{
	if (x < data->width - 1)
	{
		data->x = x;
		data->y = y;
		data->x1 = x + 1;
		data->y1 = y;
		drawrot(data);
	}
	if (y < data->height - 1)
	{
		data->x = x;
		data->y = y;
		data->x1 = x;
		data->y1 = y + 1;
		drawrot(data);
	}
}

void	rotation(t_Map *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			rotationdraw(data, x, y);
			x++;
		}
		y++;
	}
}
