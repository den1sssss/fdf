/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:21:57 by dshirely          #+#    #+#             */
/*   Updated: 2022/02/05 20:29:51 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(t_Map *data)
{
	float	xx;
	float	yy;
	float	maximum;
	int		z;
	int		z1;

	z = data->matrix[(int)data->y][(int)data->x];
	z1 = data->matrix[(int)data->y1][(int)data->x1];
	setzoom(data);
	angle(&data->x, &data->y, z, data);
	angle(&data->x1, &data->y1, z1, data);
	xx = data->x1 - data->x;
	yy = data->y1 - data->y;
	maximum = max(mod(xx), mod(yy));
	xx /= maximum;
	yy /= maximum;
	setposition(data);
	whichcolor(z, z1, data);
	while ((int)(data->x - data->x1) && (int)(data->y - data->y1))
	{
		pixput(data);
		data->x += xx;
		data->y += yy;
	}
}

void	picture(t_Map *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			drawpicture(x, y, data);
			x++;
		}
		y++;
	}
	printf("\nleftright %d\n", data->leftright);
	printf("updown %d\n\n", data->updown);
}

void	utilkey(int key, t_Map *data)
{
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
	if (data->flag == 0)
		picture(data);
	if (data->flag == 1)
		rotation(data);
	if (key == 53)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
}

int	which_key(int key, t_Map *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (key == 36 && data->flag == 0)
	{
		data->flag = 1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		rotation(data);
	}
	else if (key == 36 && data->flag == 1)
	{
		data->flag = 0;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		picture(data);
	}
	printf ("\n%d = flag\n", data->flag);
	printf("button %d", key);
	utilkey(key, data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_Map		data;
	int			**matrix;
	char		**str;

	str = NULL;
	if (argc != 2)
		write(1, "error\n", 6);
	matrix = getmap(*++argv, str);
	data = *(t_Map *)malloc(sizeof(t_Map));
	data.matrix = matrix;
	data.height = getheight(*argv);
	data.width = getwidth(*argv);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "FDF");
	default_settings(&data);
	picture(&data);
	mlx_key_hook(data.win_ptr, which_key, &data);
	mlx_loop(data.mlx_ptr);
}
