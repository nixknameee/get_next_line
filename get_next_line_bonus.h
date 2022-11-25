/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngjokaj <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:00:32 by ngjokaj           #+#    #+#             */
/*   Updated: 2022/11/23 11:00:36 by ngjokaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2022
# endif

# ifndef FD_SIZE
#  define FD_SIZE 76787
# endif
//get_next_line

char	*get_next_line(int fd);
char	*ft_read_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);

//get_nex_line_utils

size_t	ft_str_len(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif


