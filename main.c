/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:21:57 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/03 19:52:56 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void	draw(float x, float y, float x1, float y1, Map *data) //correct
{
	float	xx;
	float	yy;
	float	maximum;
	int		z;
	int		z1;

	z = data->matrix[(int)y][(int)x];
	z1 = data->matrix[(int)y1][(int)x1];
	x *= data->scale;
	x1 *= data->scale;
	y *= data->scale;
	y1 *= data->scale;
	angle(&x, &y, z, data);
	angle(&x1, &y1, z1, data);
	xx = x1 - x;
	yy = y1 - y;
	maximum = max(mod(xx), mod(yy));
	xx /= maximum;
	yy /= maximum;
	x += data->leftright;
	y += data->updown;
	x1 += data->leftright;
	y += data->updown;
	if (z > 0 || z1 > 0)
		data->color = 0xFF0000;
	else
		data->color = 0xFFFFFF;
	while ((int)(x - x1) && (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += xx;
		y += yy;
		if (x < 0 || y < 0)
			break ;
	}
}

// void	draw(Map *data) 
// {
// 	float	xx;
// 	float	yy;
// 	float	maximum;
// 	int		z;
// 	int		z1;

// 	z = data->matrix[(int)data->y][(int)data->x];
// 	z1 = data->matrix[(int)data->y1][(int)data->x1];
// 	data->x *= data->scale;
// 	data->x1 *= data->scale;
// 	data->y *= data->scale;
// 	data->y1 *= data->scale;
// 	angle(&data->x, &data->y, z, data);
// 	angle(&data->x1, &data->y1, z1, data);
// 	xx = data->x1 - data->x;
// 	yy = data->y1 - data->y;
// 	maximum = max(mod(xx), mod(yy));
// 	xx /= maximum;
// 	yy /= maximum;
// 	data->x += data->leftright;
// 	data->y += data->updown;
// 	data->x1 += data->leftright;
// 	data->y += data->updown;
// 	if (z > 0 || z1 > 0)
// 		data->color = 0xFF0000;
// 	else
// 		data->color = 0xFFFFFF;
// 	while ((int)(data->x - data->x1) && (int)(data->y - data->y1))
// 	{
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->color);
// 		data->x += xx;
// 		data->y += yy;
// 		if (data->x < 0 || data->y < 0)
// 			break ;
// 	}
// }


// void	picture(Map *data)   //correct
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < data->height)
// 	{
// 		x = 0;
// 		while (x < data->width)
// 		{
// 			// data->x = x;
// 			// data->y = y;
// 			if (x < data->width - 1)
// 			{
// 				draw(x, y, x + 1, y, data);
// 			}
// 			if (y < data->height - 1)
// 			{
// 				draw(x, y, x, y + 1, data);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	printf("\nleftright %d\n", data->leftright);
// 	printf("updown %d\n\n", data->updown);
// }


void	picture(Map *data) // correct too 
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->x = x;
			data->y = y;
			data->x1=x+1;
			data->y1=y+1;
			if (x < data->width - 1)
				draw(data->x,data->y,data->x1,data->y,data);
				// draw(data);
			if (y < data->height - 1)
				draw(data->x,data->y,data->x,data->y1,data);
				// draw(data);
			x++;
		}
		y++;
	}
	printf("\nleftright %d\n", data->leftright);
	printf("updown %d\n\n", data->updown);
}
// void rotation(Map *data)
// {
// }

int	which_key(int key, Map *data)
{
	printf("button %d", key);
	if (key == 123)
		data->leftright -= 100;
	if (key == 124)
		data->leftright += 100;
	if (key == 125)
		data->updown += 100;
	if (key == 126)
		data->updown -= 100;
	if (key == 27)
		data->scale /= 1.3;
	if (key == 24)
		data->scale *= 1.3;
	if (key == 49)
		data->angle += 0.1;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	picture(data);
	// if (key == 36)
	// 	rotation(data);
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	main(void)
{
	Map	data;
	int	**kek;
	int	i;
	int	w;
	int	h;

	kek = getmap("42.fdf");
	h = getheight("42.fdf");
	w = getwidth("42.fdf");
	i = 0;
	printf ("%d\n", h);
	printf ("%d\n", w);
	data = *(Map *)malloc(sizeof(Map));
	data.matrix = kek;
	data.height = h;
	data.width = w;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "FDF");
	default_settings(&data);
	picture(&data);
	mlx_key_hook(data.win_ptr, which_key, &data);
	mlx_loop(data.mlx_ptr);
}
