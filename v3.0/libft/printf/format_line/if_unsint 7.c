/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_unsint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:24:21 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/28 11:21:55 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		ft_width_unsint(t_fps *format_str, int max,
							int len_unsint, int null)
{
	while (max - len_unsint > 0)
	{
		if (null)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		max--;
		format_str->length_we_print++;
	}
}

void		ft_print_unsint(char *unsint_str, t_fps *format_str)
{
	if (format_str->dot >= 0)
		ft_width_unsint(format_str, format_str->dot - 1,
						ft_strlen(unsint_str) - 1, 1);
	ft_putstr_fd(unsint_str, 1);
	format_str->length_we_print += ft_strlen(unsint_str);
}

void		ft_chek_flags_unsint(char *unsint_str, t_fps *format_str)
{
	if (format_str->minus == 1)
		ft_print_unsint(unsint_str, format_str);
	if (format_str->dot >= 0 && (size_t)format_str->dot < ft_strlen(unsint_str))
		format_str->dot = ft_strlen(unsint_str);
	if (format_str->dot >= 0)
	{
		format_str->width -= format_str->dot;
		ft_width_unsint(format_str, format_str->width, 0, 0);
	}
	else
		ft_width_unsint(format_str, format_str->width,
						ft_strlen(unsint_str), format_str->null);
	if (format_str->minus == 0)
		ft_print_unsint(unsint_str, format_str);
}

void		if_unsint(unsigned int unsint, t_fps *format_str)
{
	char	*unsint_str;

	unsint = (unsigned int)(4294967295 + 1 + unsint);
	if (format_str->dot == 0 && unsint == 0)
		ft_width_unsint(format_str, format_str->width, 0, 0);
	else
	{
		unsint_str = ft_itoa_unsint(unsint);
		if (unsint_str != NULL)
		{
			ft_chek_flags_unsint(unsint_str, format_str);
			free(unsint_str);
		}
	}
}
