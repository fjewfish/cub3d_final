/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 11:04:51 by fjewfish          #+#    #+#             */
/*   Updated: 2020/05/29 11:05:37 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Parameters
** #1. The beginning of the list.
** Description
** Counts the number of elements in a list.
*/

int		ft_lstsize(t_list *lst)
{
	int		sum;
	t_list	*elem;

	sum = 0;
	if (lst)
	{
		elem = lst;
		while (elem)
		{
			elem = elem->next;
			sum++;
		}
	}
	return (sum);
}
