/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:21:08 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/26 12:40:26 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		if_char(char c, t_fps *format_str)
{
	int			char_count;

	char_count = 0;
	if (format_str->minus == 1)
		ft_putchar_fd(c, 1);
	while (format_str->width - 1 > 0)
	{
		ft_putchar_fd(' ', 1);
		format_str->width--;
		format_str->length_we_print++;
	}
	if (format_str->minus == 0)
		ft_putchar_fd(c, 1);
	format_str->length_we_print++;
}
