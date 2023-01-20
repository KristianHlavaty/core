/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:39:23 by khlavaty          #+#    #+#             */
/*   Updated: 2023/01/20 19:44:40 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
