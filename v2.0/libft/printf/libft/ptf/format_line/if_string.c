/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:21:16 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/26 17:03:02 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		ft_print_width_str(t_fps *format_str, int max, int len_we_print)
{
	while (max - len_we_print > 0)
	{
		ft_putchar_fd(' ', 1);
		max--;
		format_str->length_we_print++;
	}
}

void		ft_print_str_minus(char *str, t_fps *format_str)
{
	int		i;

	i = 0;
	if (format_str->dot >= 0)
	{
		while (str[i] && i < format_str->dot)
			ft_putchar_fd(str[i++], 1);
		ft_print_width_str(format_str, format_str->width, format_str->dot);
	}
	else
	{
		while (str[i])
			ft_putchar_fd(str[i++], 1);
		ft_print_width_str(format_str, format_str->width, ft_strlen(str));
	}
	format_str->length_we_print += i;
}

void		ft_print_str_plus(char *str, t_fps *format_str)
{
	int		i;

	i = 0;
	if (format_str->dot >= 0)
	{
		ft_print_width_str(format_str, format_str->width, format_str->dot);
		while (str[i] && i < format_str->dot)
			ft_putchar_fd(str[i++], 1);
	}
	else
	{
		ft_print_width_str(format_str, format_str->width, ft_strlen(str));
		while (str[i])
			ft_putchar_fd(str[i++], 1);
	}
	format_str->length_we_print += i;
}

void		if_string(char *str, t_fps *format_str)
{
	int		len_str;

	if (!str)
		str = "(null)";
	len_str = (int)ft_strlen(str);
	if (format_str->dot >= 0 && format_str->dot > len_str)
		format_str->dot = len_str;
	if (format_str->minus == 1)
	{
		ft_print_str_minus(str, format_str);
	}
	if (format_str->minus == 0)
	{
		ft_print_str_plus(str, format_str);
	}
}
