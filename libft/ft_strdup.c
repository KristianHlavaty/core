/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:01:38 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/03 16:08:23 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		i;

	i = 0;
	while (s[i])
		i++;
	s2 = (char *) malloc((i + 1) * sizeof(char));
	if (s2 == 0)
		return (NULL);
	while (i >= 0)
	{
		s2[i] = s[i];
		i--;
	}
	return (s2);
}
