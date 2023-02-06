/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryxaurus <kryxaurus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:34:29 by kryxaurus         #+#    #+#             */
/*   Updated: 2023/02/06 04:32:35 by kryxaurus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;
	t_list	*node;

	i = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
