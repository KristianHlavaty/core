/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:14:36 by khlavaty          #+#    #+#             */
/*   Updated: 2023/01/25 22:21:22 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*a;
	size_t		m;

	m = 0;
	a = (const char *)s;
	while (m < n)
	{
		if (a[m] == c)
		{
			return ((void *)&a[m]);
		}
		m++;
	}
	return (0);
}
