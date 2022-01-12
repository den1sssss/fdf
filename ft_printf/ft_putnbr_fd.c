/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:42:52 by dshirely          #+#    #+#             */
/*   Updated: 2021/12/10 16:54:47 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int dlina)
{
	long	chislo;

	chislo = (long)n;
	if (chislo < 0)
	{
		dlina += ft_putchar('-');
		chislo = -chislo;
	}
	if (chislo >= 10)
	{
		dlina = ft_putnbr_fd(chislo / 10, dlina);
		dlina = ft_putnbr_fd(chislo % 10, dlina);
	}
	else
		dlina += ft_putchar(chislo + '0');
	return (dlina);
}
