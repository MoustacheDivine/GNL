/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 03:10:39 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/17 01:55:11 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	set_buf(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i + j])
	{
		buffer[j] = buffer[i + j];
		j++;
	}
	buffer[j] = '\0';
}

char	*read_file(int fd, char *buffer)
{
	char	*line;
	ssize_t	bytes_read;

	bytes_read = 1;
	line = NULL;
	if (buffer[0])
	{
		line = ft_strjoin_line(line, buffer);
		if (len_char(buffer, '\n') != len_char(buffer, '\0'))
			return (line);
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		line = ft_strjoin_line(line, buffer);
		if (len_char(buffer, '\n') != len_char(buffer, '\0'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_file(fd, buffer);
	if (line == NULL)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	set_buf(buffer);
	return (line);
}
