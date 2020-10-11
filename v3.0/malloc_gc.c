/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_gc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 03:02:50 by fjewfish          #+#    #+#             */
/*   Updated: 2020/09/28 18:05:08 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header_v2.h"

/* ************************************************************************** */
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
/* ************************************************************************** */
void	*malloc_gc(size_t sizemem)
{
	void	*pointer;

	pointer = malloc(sizemem);
	memory_manager(pointer, M_ADD);
	return (pointer);
}

void	*calloc_gc(size_t nmemb, size_t size)
{
	void	*pointer;

	pointer = ft_calloc(nmemb, size);
	memory_manager(pointer, M_ADD);
	return (pointer);
}

void	free_gc(void *ptr)
{
	memory_manager(ptr, M_REMOVE);
}

static int		pointer_compare(void *ptr1, void *ptr2)
{
	return ((ptr1 == ptr2) ? 0 : 1);
}

static void		pointer_free(void *ptr)
{
	free(ptr);
}

/*
** This function collects all pointers to the allocated memory
** and clears them if necessary.
** This is implemented using a static list.
**
** The function accepts M_ADD when you need to add a pointer to the list,
** and M_REMOVE when you need to remove a pointer from the list.
** To clear the entire list of pointers, pass a null pointer!
*/

void			memory_manager(void *ptr, t_bool action)
{
	static t_list	*collector = NULL;

	if (ptr == NULL)
		ft_lstclear(&collector, &pointer_free);
	else if (action == M_ADD)
		ft_lstadd_front(&collector, ft_lstnew(ptr));
	else if (action == M_REMOVE)
		ft_lstdelel(&collector, ptr, pointer_compare, pointer_free);
}

char	*ft_strdup_gc(char *s1)
{
	char *s_cpy;

	s_cpy = (char *)malloc_gc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s_cpy == NULL)
		return (NULL);
	return (ft_strcpy(s_cpy, (char *)s1));
}
