/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 12:06:19 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/26 20:01:10 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

/*
** initialize format string list
*/

void		ft_init_format_str(t_fps *format_str)
{
	format_str->length_format = 0;
	format_str->length_we_print = 0;
	format_str->type = 0;
	format_str->width = 0;
	format_str->minus = 0;
	format_str->null = 0;
	format_str->star_double = 0;
	format_str->dot = -1;
	format_str->whitespace = 0;
	format_str->plus = 0;
	format_str->octothorpe = 0;
}

/*
** parse all flags
**
** also check width
** if they are not *
** return i value if we found it
*/

void		ft_parse_flags_wbonus(const char *line, t_fps *format_str, int *i)
{
	if (line[*i] == '0' && format_str->width == 0 && format_str->minus == 0)
	{
		format_str->length_format++;
		format_str->null = 1;
	}
	else
		while (ft_isdigit(line[*i]))
			if_digit(line[(*i)++], format_str);
	if (line[*i] == ' ' && format_str->plus == 0)
	{
		format_str->whitespace = 1;
		format_str->length_format++;
	}
	if (line[*i] == '+')
	{
		format_str->plus = 1;
		format_str->whitespace = 0;
		format_str->length_format++;
	}
	if (line[*i] == '#')
	{
		format_str->octothorpe = 1;
		format_str->length_format++;
	}
}

/*
** parse our fomat line
** break if we found type
*/

void		ft_parse_fps(const char *line, t_fps *format_str,
			va_list argptr, int i)
{
	ft_init_format_str(format_str);
	while (line[i] && (ft_type_wework(line[i]) || (ft_flag_wework(line[i]))
			|| (ft_isdigit(line[i]))))
	{
		ft_parse_flags_wbonus(line, format_str, &i);
		if (line[i] == '.')
			if_dot(line, &i, format_str, argptr);
		if (line[i] == '-')
			if_minus(format_str);
		if (line[i] == '*')
			if_width(argptr, format_str);
		if (ft_type_wework(line[i]))
		{
			format_str->type = line[i];
			break ;
		}
		i++;
	}
}
