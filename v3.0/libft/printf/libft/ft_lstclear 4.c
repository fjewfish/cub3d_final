/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:57:07 by fjewfish          #+#    #+#             */
/*   Updated: 2020/06/03 01:35:10 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The adress of a pointer to an element.
** #2. The adress of the function used to delete the
** content of the element.
** Description
** Deletes and frees the given element and every
** successor of that element, using the function ’del’
** and free(3).
** Finally, the pointer to the list must be set to
** NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*nxt;

	if (*lst == NULL)
		return ;
	elem = *lst;
	nxt = elem->next;
	while (elem)
	{
		nxt = elem->next;
		(*del)(elem->content);
		free(elem);
		elem = nxt;
	}
	*lst = NULL;
}
