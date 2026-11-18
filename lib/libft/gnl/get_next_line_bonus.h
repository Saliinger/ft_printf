/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:20:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 15:01:39 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//# include <stdarg.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

// Buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// base function
char	*get_next_line(int fd);

// utils function
int		ft_strlen_gnl(char const *s);
char	*ft_strncpy_gnl(char *dest, char *src, unsigned int n);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_verify(char *stash);
char	*ft_clean(char *stash);

#endif
