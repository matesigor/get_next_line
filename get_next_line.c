/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwietzke <iwietzke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:53:26 by iwietzke          #+#    #+#             */
/*   Updated: 2024/07/14 09:51:21 by iwietzke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*left;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left = function_read (fd, left);
	if (!left)
		return (NULL);
	line = ft_getlines(left);
	left = ft_getlefts(left);
	return (line);
}

char	*function_read(int fd, char *str)
{
	char	*temp;
	int		bytes_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && (bytes_read != 0))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_getlines(char *left)
{
	int		i;
	char	*line;

	i = 0;
	if (!left[i])
		return (NULL);
	while (left[i] && left[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left[i] && left[i] != '\n')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
	{
		line[i] = left[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getlefts(char *left)
{
	char	*rest;
	int		i;
	int		j;
	int		l;

	i = ft_strlen(left, '\n');
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	l = ft_strlen(left, '\0');
	rest = (char *)malloc(sizeof(char) * (l - i + 1));
	if (!rest)
	{
		free(rest);
		return (NULL);
	}
	i++;
	j = 0;
	while (left[i])
		rest[j++] = left[i++];
	rest[j] = '\0';
	free(left);
	return (rest);
}

/*int main(void) {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    char *line;
    int line_number = 1;
    while ((line = get_next_line(fd)) != NULL) {
        printf("Linha %d: %s\n", line_number, line);
        free(line);
        line_number++;
    }
    close(fd);
    return 0;
}*/
