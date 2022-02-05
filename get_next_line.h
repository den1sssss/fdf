/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirely <dshirely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:26:52 by dshirely          #+#    #+#             */
/*   Updated: 2022/01/23 18:13:14 by dshirely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		ft_strlenn(char *str);
int		indexkek(char *str);
char	*ft_strdupp(char *str);
char	*ft_strjoinn(char *str, char *kek);
char	*perdelstr(char *str);
char	*ostatok(char *str, int fd);
char	*strochka(char *str);
char	*get_next_line(int fd);

#endif
