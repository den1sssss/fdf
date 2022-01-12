/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:42:43 by dshirely          #+#    #+#             */
/*   Updated: 2021/12/10 17:08:06 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ultrakek(va_list ptr, int i)
{
	if (i == 'c')
		return (ft_putchar(va_arg(ptr, int)));
	if (i == 'd' || i == 'i')
		return (ft_putnbr_fd(va_arg(ptr, int), 0));
	if (i == 's')
		return (ft_putstr(va_arg(ptr, char *)));
	if (i == '%')
		return (write(1, "%", 1));
	if (i == 'u')
		return (ft_putnbru(va_arg(ptr, unsigned int), 0));
	if (i == 'x')
		return (ft_xxx(va_arg(ptr, unsigned int), 'a', 16));
	if (i == 'X')
		return (ft_xxx(va_arg(ptr, unsigned int), 'A', 16));
	if (i == 'p')
		return (ft_pointer(va_arg(ptr, unsigned long)));
	return (write (1, "%", 1));
}

static int	itog(va_list ptr, const char *kek)
{
	int	count;
	int	i;
	int	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (kek[i])
	{
		if (flag == 1)
		{
			count += ultrakek(ptr, kek[i]);
			flag = 0;
		}
		else
		{
			if (kek[i] == '%')
				flag = 1;
			else
				count += write (1, &kek[i], 1);
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *kek, ...)
{
	va_list	ptr;

	va_start(ptr, kek);
	va_end(ptr);
	return (itog(ptr, kek));
}
