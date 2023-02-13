/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:59:29 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/13 22:14:40 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_store(char *str)
{
	char	*rest;
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	rest = (char *)malloc(ft_strlen(str) + 1 - i);
	if (!rest)
		return (0);
	i++;
	while (str[i])
		rest[x++] = str[i++];
	rest[x] = '\0';
	free(str);
	return (rest);
}

char	*ft_append(int fd, char *str)
{
	int		readen;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (0);
	readen = 1;
	while (readen > 0 && !ft_strrchr(str, '\n'))
	{
		readen = read(fd, buffer, BUFFER_SIZE);
		if (readen == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[readen] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*out;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	out = (char *)malloc(i + 2);
	if (!out)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		out[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		out[i] = str[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	str = ft_append(fd, str);
	if (!str)
		return (0);
	line = ft_get_line(str);
	str = ft_store(str);
	return (line);
}
