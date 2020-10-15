/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m2_malloc_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <fjewfish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 17:07:46 by fjewfish          #+#    #+#             */
/*   Updated: 2020/10/12 17:19:30 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

/*
** This function collects all pointers to the allocated memory
** and clears them if necessary.
** This is implemented using a static list.
**
** The function accepts M_ADD when you need to add a pointer to the list,
** and M_REMOVE when you need to remove a pointer from the list.
** To clear the entire list of pointers, pass a null pointer!
*/

void		memory_manager(void *ptr, t_bool action)
{
	static t_list	*collector = NULL;

	if (ptr == NULL)
		ft_lstclear(&collector, &pointer_free);
	else if (action == M_ADD)
		ft_lstadd_front(&collector, ft_lstnew(ptr));
	else if (action == M_REMOVE)
		ft_lstdelel(&collector, ptr, pointer_compare, pointer_free);
}

static int	pointer_compare(void *ptr1, void *ptr2)
{
	return ((ptr1 == ptr2) ? 0 : 1);
}

static void	pointer_free(void *ptr)
{
	free(ptr);
}

static void	delete(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void		ft_lstdelel(t_list **lst, void *content, int (*cmp)(void *, void *),
						void (*del)(void *))
{
	t_list	*tmp;
	t_list	*pre;

	if (cmp((*lst)->content, content) == 0)
	{
		tmp = (*lst)->next;
		delete(*lst, del);
		*lst = tmp;
		return ;
	}
	pre = *lst;
	tmp = pre->next;
	while (tmp)
	{
		if (cmp(tmp->content, content) == 0)
		{
			pre->next = tmp->next;
			delete(tmp, del);
			return ;
		}
		pre = pre->next;
		tmp = tmp->next;
	}
}
