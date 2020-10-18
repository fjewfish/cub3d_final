/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 15:35:09 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/26 12:45:39 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		ft_print_format_line(t_fps *format_str, va_list argptr)
{
	if (format_str->type == 'c')
		if_char(va_arg(argptr, int), format_str);
	else if (format_str->type == 's')
		if_string(va_arg(argptr, char *), format_str);
	else if (format_str->type == 'd' || format_str->type == 'i')
		if_int(va_arg(argptr, int), format_str);
	else if (format_str->type == '%')
		if_percent(format_str);
	else if (format_str->type == 'p')
		if_pointer(va_arg(argptr, unsigned long long), format_str);
	else if (format_str->type == 'u')
		if_unsint((unsigned int)va_arg(argptr, unsigned int),
		format_str);
	else if (format_str->type == 'x')
		if_hexadecimal_x(va_arg(argptr, unsigned int), format_str);
	else if (format_str->type == 'X')
		if_hexadecimal(va_arg(argptr, unsigned int), format_str);
}
