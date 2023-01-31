/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:48:47 by khlavaty          #+#    #+#             */
/*   Updated: 2023/01/31 18:30:10 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fts_freeall(char **res, int k)
{
	while (k-- > 0)
		free(res[k]);
	free(res);
	return (NULL);
}

static int	fts_countwords(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	fts_countchars(const char *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		vars[3];

	if (s == 0)
		return (0);
	res = malloc(sizeof(char *) * (fts_countwords(s, c) + 1));
	if (!res)
		return (NULL);
	vars[0] = -1;
	vars[2] = 0;
	while (++vars[0] < fts_countwords(s, c))
	{
		vars[1] = 0;
		res[vars[0]] = malloc(fts_countchars(s, c, vars[2]) + 1);
		if (!res[vars[0]])
			return (fts_freeall(res, vars[0]));
		while (s[vars[2]] != '\0' && s[vars[2]] == c)
			vars[2]++;
		while (s[vars[2]] != c && s[vars[2]] != '\0')
			res[vars[0]][vars[1]++] = s[vars[2]++];
		res[vars[0]][vars[1]] = '\0';
	}
	res[vars[0]] = NULL;
	return (res);
}
