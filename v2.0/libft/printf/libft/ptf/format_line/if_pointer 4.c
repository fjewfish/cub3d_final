/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:21:13 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/28 11:20:29 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		ft_width_pointer(t_fps *format_str, int max, int len_pn, int null)
{
	while (max - len_pn > 0)
	{
		if (null)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		max--;
		format_str->length_we_print++;
	}
}

void		ft_print_pointer(char *pointer, t_fps *format_str)
{
	int		i;

	i = 0;
	ft_putstr_fd("0x", 1);
	format_str->length_we_print += 2;
	if (format_str->dot >= 0)
	{
		ft_width_pointer(format_str, format_str->dot, ft_strlen(pointer), 1);
		while (pointer[i] && i < format_str->dot)
		{
			ft_putchar_fd(pointer[i], 1);
			i++;
			format_str->length_we_print++;
		}
	}
	else
	{
		ft_putstr_fd(pointer, 1);
		format_str->length_we_print += ft_strlen(pointer);
	}
}

int			if_pointer(unsigned long long pn, t_fps *format_str)
{
	char	*pointer;
	int		len_pointer;

	if (pn == 0 && format_str->dot == 0)
	{
		format_str->length_we_print += 2;
		ft_width_pointer(format_str, format_str->width, 2, 0);
		ft_putstr_fd("0x", 1);
		return (1);
	}
	if (!(pointer = ft_itoa_pointer(pn)))
		return (1);
	len_pointer = (int)ft_strlen(pointer);
	if (format_str->dot < len_pointer)
		format_str->dot = len_pointer;
	if (format_str->minus == 1)
		ft_print_pointer(pointer, format_str);
	ft_width_pointer(format_str, format_str->width, len_pointer + 2, 0);
	if (format_str->minus == 0)
		ft_print_pointer(pointer, format_str);
	free(pointer);
	return (1);
}
