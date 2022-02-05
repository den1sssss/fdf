/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:26:34 by dshirely          #+#    #+#             */
/*   Updated: 2022/01/23 16:11:03 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ostatok(char *str, int fd)
{
	char	*buf;
	int		prochitannoe;

	if (indexkek(str) != -1)
		return (str);
	buf = malloc(BUFFER_SIZE + 1);
	buf[0] = 0;
	while (indexkek(buf) == -1)
	{
		prochitannoe = read(fd, buf, BUFFER_SIZE);
		if (prochitannoe == -1)
		{
			free(buf);
			return (NULL);
		}
		if (prochitannoe == 0)
			break ;
		buf[prochitannoe] = 0;
		str = ft_strjoinn(str, buf);
	}
	free(buf);
	return (str);
}

char	*strochka(char *str)
{
	int		i;
	char	*kek;
	int		j;

	if (!str)
		return (NULL);
	if (!str[0])
		return (NULL);
	i = indexkek(str);
	if (i == -1)
		return (ft_strdupp(str));
	kek = malloc(i + 1);
	j = 0;
	while (j < i + 1)
	{
		kek[j] = str[j];
		j++;
	}
	kek[j] = '\0';
	return (kek);
}

char	*get_next_line(int fd)
{
	static char	*ostatki;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ostatki = ostatok(ostatki, fd);
	if (!ostatki)
		return (NULL);
	str = strochka(ostatki);
	ostatki = perdelstr(ostatki);
	return (str);
}
