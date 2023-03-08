/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:30:08 by khlavaty          #+#    #+#             */
/*   Updated: 2023/03/06 18:13:16 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	**ft_split(char *str)
{
	int	i;
	int	j;
	int	k;
	int	word_count;
	int	len;

	i = 0;
	j = 0;
	k = 0;
	word_count = 0;
	len = ft_strlen(str);

	while (i < len)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
		{
			i++;
		}
		if (str[i])
		{
			word_count++;
			while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			{
				i++;
			}
		}
	}
	char	**result = (char**)malloc(sizeof(char*) * (word_count + 1));
	if (result == NULL)
	{
		return NULL;
	}
	i = 0;
	while (i < len)
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' && str[i] == '\n'))
		{
			i++;
		}
		if (str[i])
		{
			j = i;
			while (str[j] && (str[j] != ' ' && str[j] != '\t' && str[j] != '\n'))
			{
				j++;
			}
			result[k] = (char*)malloc(sizeof(char) * (j - i + 1));
			if (result[k] == NULL)
			{
				return NULL;
			}
			ft_strncpy(result[k], str + i, j - i);
			result[k][j - i] = '\0';
			k++;
			i = j;
		}
	}
	result[k] = NULL;
	return result;
}
