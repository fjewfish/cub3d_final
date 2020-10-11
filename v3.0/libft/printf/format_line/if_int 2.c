/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:24:09 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/28 11:27:23 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		ft_width_int(t_fps *format_str, int max, int len_int, int null)
{
	while (max - len_int > 0)
	{
		if (null)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		max--;
		format_str->length_we_print++;
	}
}

void		ft_print_int(char *int_str, int save_i, t_fps *format_str)
{
	int		len_di;
	int		i;

	len_di = (int)ft_strlen(int_str);
	i = 0;
	if (save_i < 0 && format_str->dot >= 0)
		ft_putchar_fd('-', 1);
	if (save_i >= 0 && format_str->plus == 1)
		ft_putchar_fd('+', 1);
	if (save_i >= 0 && format_str->whitespace == 1)
		ft_putchar_fd(' ', 1);
	if (format_str->dot >= 0)
		ft_width_int(format_str, format_str->dot - 1, len_di - 1, 1);
	while (int_str[i] && i < len_di)
		ft_putchar_fd(int_str[i++], 1);
	format_str->length_we_print += i;
}

void		ft_chek_flags_int(char *int_str, int save_i, t_fps *format_str)
{
	int		len_di;

	len_di = (int)ft_strlen(int_str);
	if (format_str->minus == 1)
		ft_print_int(int_str, save_i, format_str);
	if (format_str->dot >= 0 && format_str->dot < len_di)
		format_str->dot = len_di;
	if (format_str->dot >= 0)
	{
		format_str->width -= format_str->dot;
		ft_width_int(format_str, format_str->width, 0, 0);
	}
	else
		ft_width_int(format_str, format_str->width, len_di, format_str->null);
	if (format_str->minus == 0)
		ft_print_int(int_str, save_i, format_str);
}

int			ft_check_negative_plus_whirespase(t_fps *format_str, int i,
											int *if_minint)
{
	if (format_str->plus == 1)
	{
		format_str->width--;
		format_str->length_we_print++;
	}
	if (i < 0 && (format_str->dot >= 0 || format_str->null == 1))
	{
		if (format_str->null == 1 && format_str->dot == -1 && i)
			ft_putchar_fd('-', 1);
		if (i == -2147483648)
		{
			*if_minint = 1;
			i = -2147483647;
		}
		i *= -1;
		format_str->null = 1;
		format_str->width--;
		format_str->length_we_print++;
		format_str->whitespace = 0;
	}
	return (i);
}

int			if_int(int i, t_fps *format_str)
{
	char	*int_str;
	int		save_i;
	int		if_minint;

	save_i = i;
	if_minint = 0;
	if (format_str->dot == 0 && i == 0)
	{
		ft_width_int(format_str, format_str->width, 0, 0);
		return (1);
	}
	i = ft_check_negative_plus_whirespase(format_str, i, &if_minint);
	if (format_str->whitespace == 1)
	{
		format_str->width--;
		format_str->length_we_print++;
	}
	if (!(int_str = ft_itoa(i)))
		return (1);
	if (if_minint)
		int_str[ft_strlen(int_str) - 1] = '8';
	ft_chek_flags_int(int_str, save_i, format_str);
	free(int_str);
	return (1);
}
