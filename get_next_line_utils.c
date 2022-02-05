/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:26:47 by dshirely          #+#    #+#             */
/*   Updated: 2022/01/23 18:58:11 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlenn(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	indexkek(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdupp(char *str)
{
	char	*kek;
	size_t	i;

	kek = malloc(ft_strlenn(str) + 1);
	i = 0;
	while (str[i])
	{
		kek[i] = str[i];
		i++;
	}
	kek[i] = '\0';
	return (kek);
}

char	*ft_strjoinn(char *str, char *kek)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = -1;
	j = 0;
	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !kek)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlenn(str) + ft_strlenn(kek)) + 1);
	if (result == NULL)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			result[i] = str[i];
	while (kek[j] != '\0')
		result[i++] = kek[j++];
	result[ft_strlenn(str) + ft_strlenn(kek)] = '\0';
	free(str);
	return (result);
}

char	*perdelstr(char *str)
{
	int		i;
	char	*perdelstroka;

	i = indexkek(str);
	if (i == -1)
	{
		free(str);
		return (NULL);
	}
	perdelstroka = ft_strdupp(str + i + 1);
	free(str);
	return (perdelstroka);
}
