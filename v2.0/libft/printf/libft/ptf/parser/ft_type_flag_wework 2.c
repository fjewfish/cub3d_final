/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_flag_wework.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 17:43:03 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/25 01:50:55 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

/*
** return 1 if we treat this type*.
*/

int			ft_type_wework(int type)
{
	if ((type == 'c') || (type == 's') || (type == 'p') || (type == 'd')
		|| (type == 'i') || (type == 'u') || (type == 'x') || (type == 'X')
		|| (type == '%'))
		return (1);
	else
		return (0);
}

/*
** return 1 if we treat this flag*.
*/

int			ft_flag_wework(int flag)
{
	if ((flag == '-') || (flag == '0') || (flag == '.') || (flag == '*')
		|| (flag == ' ') || (flag == '+') || (flag == '#'))
		return (1);
	else
		return (0);
}
