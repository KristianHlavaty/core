/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:59:26 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/13 21:42:24 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char		*last;
	const char	*thisstr;

	last = NULL;
	c = c % 128;
	thisstr = s;
	while (*thisstr != '\0')
	{
		if (*thisstr == (char)c)
		{
			last = (char *)thisstr;
		}
		thisstr++;
	}
	if (*thisstr == (char)c)
	{
		last = (char *)thisstr;
	}
	return (last);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc(lens1 + lens2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	while ((i - lens1) < lens2)
	{
		str[i] = s2[i - lens1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
