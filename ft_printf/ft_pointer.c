/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:42:40 by dshirely          #+#    #+#             */
/*   Updated: 2021/12/10 16:56:43 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long str)
{
	int	count;

	if (!str)
	{
		write (1, "0x0", 3);
		return (3);
	}
	else
	{
		count = write (1, "0x", 2);
		count += ft_xxx(str, 'a', 16);
	}
	return (count);
}
