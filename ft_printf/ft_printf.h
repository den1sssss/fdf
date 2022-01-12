/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:42:46 by dshirely          #+#    #+#             */
/*   Updated: 2021/12/10 16:55:56 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *kek, ...);
int		ft_putnbr_fd(int n, int fd);
int		ft_xxx(unsigned long chislo, char bukva, int osn);
int		ft_putnbru(unsigned int a, int number);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_pointer(unsigned long str);

#endif