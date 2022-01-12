/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:43:00 by dshirely          #+#    #+#             */
/*   Updated: 2021/12/10 16:53:20 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	numb_len(unsigned long a)
{
	int	i;

	i = 0;
	while (a > 0)
	{
		a /= 16;
		i++;
	}
	return (i);
}

static char	wtozabukva(chislo, bukva)
{
	char	c;

	if (chislo >= 10)
		c = chislo - 10 + bukva;
	else
		c = chislo + '0';
	return (c);
}

void	writehex16(char *simvol, int count)
{
	count -= 1;
	while (count >= 0)
	{
		write (1, &simvol[count], 1);
		count--;
	}
}

int	ft_xxx(unsigned long chislo, char bukva, int osn)
{
	int		ostatok;
	char	*simvol;
	int		count;

	if (chislo == 0)
		return (write (1, "0", 1));
	simvol = (char *)malloc(sizeof(char) * numb_len(chislo) + 1);
	count = 0;
	while (chislo != 0)
	{
		ostatok = chislo % osn;
		chislo /= osn;
		simvol[count] = wtozabukva(ostatok, bukva);
		count++;
	}
	simvol[count] = '\0';
	writehex16(simvol, count);
	free(simvol);
	return (count);
}
