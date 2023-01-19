/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:31:14 by khlavaty          #+#    #+#             */
/*   Updated: 2023/01/19 21:29:38 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	concat;

	i = 0;
	j = 0;
	concat = 0;
	while (dst[i] != '\0' && !(dst == NULL && size == 0) && i < size)
		i++;
	while (src[j] != '\0' && !(src == NULL && size == 0))
		j++;
	if (size > i)
		concat = i + j;
	else
		concat = size + j;
	j = 0;
	while (src[j] != '\0' && (i < size - 1) && size != 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (size > i)
		dst[i] = '\0';
	return (concat);
}
