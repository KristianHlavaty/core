/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kryxaurus <kryxaurus@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:51:19 by kryxaurus         #+#    #+#             */
/*   Updated: 2023/02/06 04:32:28 by kryxaurus        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if(!*lst)
	{
		*lst = new;
	}
	else
	{
		node = ft_lstlast(*lst);
		node->next = new;
	}
}
