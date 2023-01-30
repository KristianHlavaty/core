/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:32:14 by khlavaty          #+#    #+#             */
/*   Updated: 2023/01/30 17:12:44 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subs;
	size_t	s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		subs = malloc(sizeof(char));
	}
	if (len > s_len - start)
		len = s_len - start;
	subs = malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	while (i < len && s[start + i] && !(start > s_len))
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
