/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsplus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:59:15 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/05 19:55:25 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawpicture(int x, int y, t_Map *data)
{
	if (x < data->width - 1)
	{
		data->x = x;
		data->y = y;
		data->x1 = x + 1;
		data->y1 = y;
		draw(data);
	}
	if (y < data->height - 1)
	{
		data->x = x;
		data->y = y;
		data->x1 = x;
		data->y1 = y + 1;
		draw(data);
	}
}

void	whichcolor(int z, int z1, t_Map *data)
{
	if (z > 0 || z1 > 0)
		data->color = 0xFF0000;
	else
		data->color = 0xFFFFFF;
}

void	setposition(t_Map *data)
{
	data->x += data->leftright;
	data->y += data->updown;
	data->x1 += data->leftright;
	data->y1 += data->updown;
}

void	setzoom(t_Map *data)
{
	data->x *= data->scale;
	data->x1 *= data->scale;
	data->y *= data->scale;
	data->y1 *= data->scale;
}
