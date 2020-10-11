/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 10:55:15 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 10:56:00 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The address of a pointer to the first link of
** a list.
** #2. The address of a pointer to the element to be
** added to the list.
** Description
** Adds the element ’new’ at the end of the list.
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *elem;

	if (*lst == NULL)
		*lst = new;
	else
	{
		elem = *lst;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
	}
}
