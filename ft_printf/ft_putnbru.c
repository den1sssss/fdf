/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:42:55 by dshirely          #+#    #+#             */
/*   Updated: 2021/12/10 16:54:31 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int a, int number)
{
	if (a >= 10)
	{
		number = ft_putnbru(a / 10, number);
		number = ft_putnbru(a % 10, number);
	}
	else
		number += ft_putchar(a + '0');
	return (number);
}
