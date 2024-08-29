/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwietzke <iwietzke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:33:52 by iwietzke          #+#    #+#             */
/*   Updated: 2024/07/11 20:46:27 by iwietzke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*function_read(int fd, char *str);
char	*ft_getlines(char *left);
char	*ft_getlefts(char *left);
size_t	ft_strlen(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);

#endif
