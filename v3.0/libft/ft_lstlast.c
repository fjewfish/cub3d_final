/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:02:17 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 11:02:41 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The beginning of the list.
** Description
** Returns the last element of the list.
*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list *elem;

	if (lst)
	{
		elem = lst;
		while (elem->next)
			elem = elem->next;
	}
	else
		return (0);
	return (elem);
}
