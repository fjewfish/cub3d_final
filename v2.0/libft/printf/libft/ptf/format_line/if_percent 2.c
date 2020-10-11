/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:24:14 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/26 17:03:34 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		if_percent(t_fps *format_str)
{
	if (format_str->minus == 1)
	{
		ft_putchar_fd('%', 1);
		format_str->length_we_print++;
	}
	while (format_str->width - 1 > 0)
	{
		if (format_str->null)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		format_str->width--;
		format_str->length_we_print++;
	}
	if (format_str->minus == 0)
	{
		ft_putchar_fd('%', 1);
		format_str->length_we_print++;
	}
}
