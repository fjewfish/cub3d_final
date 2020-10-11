/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 18:24:06 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/28 11:27:50 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

void		ft_width_hexadecimal(t_fps *format_str, int max,
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

void		ft_print_hexadecial(char *hexa_str, t_fps *format_str,
								int len_hexa, int x)
{
	if (x == 1 && format_str->octothorpe == 1)
		ft_putstr_fd("0x", 1);
	if (x == 2 && format_str->octothorpe == 1)
		ft_putstr_fd("0X", 1);
	if (format_str->dot >= 0)
		ft_width_unsint(format_str, format_str->dot - 1, len_hexa - 1, 1);
	ft_putstr_fd(hexa_str, 1);
	format_str->length_we_print += len_hexa;
}

void		ft_chek_flags_hexadecimal(char *hexa_str, t_fps *format_str, int x)
{
	int		len_hexa;

	len_hexa = (int)ft_strlen(hexa_str);
	if (format_str->minus == 1)
		ft_print_hexadecial(hexa_str, format_str, len_hexa, x);
	if (format_str->dot >= 0 && format_str->dot < len_hexa)
		format_str->dot = len_hexa;
	if (format_str->dot >= 0)
	{
		format_str->width -= format_str->dot;
		ft_width_hexadecimal(format_str, format_str->width, 0, 0);
	}
	else
		ft_width_hexadecimal(format_str, format_str->width,
							len_hexa, format_str->null);
	if (format_str->minus == 0)
		ft_print_hexadecial(hexa_str, format_str, len_hexa, x);
}

/*
** overflow
** use tolower
*/

int			if_hexadecimal_x(unsigned int unsint, t_fps *format_str)
{
	char	*hexa_str;
	int		i;

	i = 0;
	if (format_str->octothorpe == 1 && unsint != 0)
	{
		format_str->width -= 2;
		format_str->length_we_print += 2;
	}
	unsint = (unsigned int)(4294967295 + 1 + unsint);
	if (format_str->dot == 0 && unsint == 0)
		ft_width_hexadecimal(format_str, format_str->width, 0, 0);
	else
	{
		if (!(hexa_str = ft_itoa_hexadecimal(unsint)))
			return (1);
		while (hexa_str[i])
		{
			hexa_str[i] = ft_tolower(hexa_str[i]);
			i++;
		}
		ft_chek_flags_hexadecimal(hexa_str, format_str, 1);
		free(hexa_str);
	}
	return (1);
}

/*
** overflow
*/

void		if_hexadecimal(unsigned int unsint, t_fps *format_str)
{
	char	*hexa_str;

	if (format_str->octothorpe == 1 && unsint != 0)
	{
		format_str->width -= 2;
		format_str->length_we_print += 2;
	}
	unsint = (unsigned int)(4294967295 + 1 + unsint);
	if (format_str->dot == 0 && unsint == 0)
		ft_width_hexadecimal(format_str, format_str->width, 0, 0);
	else
	{
		hexa_str = ft_itoa_hexadecimal(unsint);
		if (hexa_str != NULL)
		{
			ft_chek_flags_hexadecimal(hexa_str, format_str, 2);
			free(hexa_str);
		}
	}
}
