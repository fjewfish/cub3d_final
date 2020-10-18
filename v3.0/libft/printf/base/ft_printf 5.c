/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:37:46 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/27 00:57:16 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

/*
** putchar_fd which count line we print
*/

void		ft_putchar_fd_modified(char c, int fd, int *line_length)
{
	if (fd >= 0)
	{
		write(fd, &c, 1);
		(*line_length)++;
	}
}

/*
** parse format string
** print our line
** return length value we print
*/

int			ft_read_format(const char *line, va_list argptr, t_fps *format_str,
							int line_length)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '%' && line[i + 1])
		{
			i++;
			ft_parse_fps(line, format_str, argptr, i);
			i += format_str->length_format;
			if (!line[i])
				break ;
			if (ft_type_wework(line[i]))
			{
				ft_print_format_line(format_str, argptr);
				line_length += format_str->length_we_print;
			}
		}
		else if (line[i])
			ft_putchar_fd_modified(line[i], 1, &line_length);
		i++;
	}
	return (line_length);
}

/*
** main function which create format_str list and return length we print
*/

int			ft_printf(const char *line, ...)
{
	int		line_length_read;
	va_list	argptr;
	t_fps	*format_str;

	line_length_read = 0;
	if (!(format_str = malloc(sizeof(t_fps))))
		return (0);
	va_start(argptr, line);
	line_length_read = ft_read_format(line, argptr, format_str,
										line_length_read);
	va_end(argptr);
	free(format_str);
	return (line_length_read);
}
