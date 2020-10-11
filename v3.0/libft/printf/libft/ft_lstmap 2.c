/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:03:09 by fjewfish          #+#    #+#             */
/*   Updated: 2020/06/03 01:41:43 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The adress of a pointer to an element.
** #2. The adress of the function used to iterate on
** the list.
** #3. The adress of the function used to delete the
** content of an element if needed.
** Description
** Iterates the list ’lst’ and applies the function
** ’f’ to the content of each element. Creates a new
** list resulting of the successive applications of
** the function ’f’. The ’del’ function is used to
** delete the content of an element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*elem;
	t_list	*lst_begin;

	if (!lst || !f)
		return (NULL);
	if (!(lst_begin = ft_lstnew((*f)(lst->content))))
		return (NULL);
	elem = lst_begin;
	lst = lst->next;
	while (lst)
	{
		if (!(elem->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lst_begin, del);
			return (NULL);
		}
		elem = elem->next;
		lst = lst->next;
	}
	return (lst_begin);
}
