/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbruscan <gbruscan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:39:52 by gbruscan          #+#    #+#             */
/*   Updated: 2024/10/17 01:56:56 by gbruscan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	len_char(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin_line(char *line, char *buffer)
{
	char	*mem;
	int		i;
	int		j;

	i = 0;
	j = 0;
	mem = (char *)malloc(len_char(line, '\0') + len_char(buffer, '\n') + 2);
	if (!mem)
		return (NULL);
	while (line && line[j])
		mem[i++] = line[j++];
	j = 0;
	while (buffer && buffer[j] && buffer[j] != '\n')
		mem[i++] = buffer[j++];
	mem[i] = '\n';
	if (buffer[j] == '\n')
		i++;
	mem[i] = '\0';
	if (line)
		free(line);
	return (mem);
}
