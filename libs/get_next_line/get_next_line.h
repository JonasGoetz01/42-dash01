/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgotz <jgotz@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 07:48:29 by lzipp             #+#    #+#             */
/*   Updated: 2023/11/04 16:29:22 by jgotz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

char	*get_next_line(int fd);

char	*next_line(char **text);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s);

int		sep_inside(char *str);

int		catch_errors(int nbt, char **text);

int		file_text(char **text, char *buffer);

#endif
