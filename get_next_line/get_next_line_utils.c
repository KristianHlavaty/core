/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:59:26 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/13 22:43:33 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = (char *) s;
	i = 0;
	if (c == '\0')
		return (str + ft_strlen(str));
	if (*s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] % 256 == c % 256)
			return (str);
		str++;
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*out;
	int		i;
	int		x;

	x = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	out = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!out)
		return (0);
	while (s1[x] != '\0')
		out[i++] = s1[x++];
	x = 0;
	while (s2[x] != '\0')
		out[i++] = s2[x++];
	out[i] = '\0';
	free(s1);
	return (out);
}
