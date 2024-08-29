/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwietzke <iwietzke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:01:04 by iwietzke          #+#    #+#             */
/*   Updated: 2024/07/14 09:17:45 by iwietzke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s, char c)
{
	char	*i;

	i = s;
	if (!s)
		return (0);
	while (*i && *i != c)
		i++;
	return (i - s);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(str1, '\0');
	len2 = ft_strlen(str2, '\0');
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = str1[i];
	j = -1;
	while (++j < len2)
		result[i + j] = str2[j];
	result[i + j] = '\0';
	free(str1);
	return (result);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	return (0);
}
