/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:56:04 by khlavaty          #+#    #+#             */
/*   Updated: 2023/01/30 18:26:03 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
