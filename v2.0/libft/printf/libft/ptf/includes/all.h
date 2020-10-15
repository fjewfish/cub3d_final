/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjewfish <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:42:58 by fjewfish          #+#    #+#             */
/*   Updated: 2020/07/28 11:25:10 by fjewfish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_fps
{
	int				length_format;
	int				length_we_print;
	int				type;
	int				width;
	int				minus;
	int				null;
	int				dot;
	int				star_double;
	int				plus;
	int				whitespace;
	int				octothorpe;
}					t_fps;

/*
** BASE
*/

int					ft_printf(const char *line, ...);
int					ft_read_format(const char *line, va_list argptr,
								t_fps *format_str, int line_length);
void				ft_putchar_fd_modified(char c, int fd, int *line_length);

/*
** PARSER
*/

void				ft_parse_fps(const char *line, t_fps *format_str,
								va_list argptr, int i);
void				ft_parse_flags_wbonus(const char *line,
											t_fps *format_str, int *i);
void				ft_init_format_str(t_fps *format_str);
int					ft_type_wework(int type);
int					ft_flag_wework(int flag);
void				if_dot(const char *line, int *start,
					t_fps *format_str, va_list argptr);
void				if_minus(t_fps *format_str);
void				if_width(va_list argptr, t_fps *format_str);
void				if_digit(char digit, t_fps *format_str);

/*
** FORMAT_LINE
*/

void				ft_print_format_line(t_fps *format_str, va_list argptr);

/*
** char
*/

void				if_char(char c, t_fps *format_str);

/*
** string
*/

void				if_string(char *str, t_fps *format_str);
void				ft_print_str_plus(char *str, t_fps *format_str);
void				ft_print_str_minus(char *str, t_fps *format_str);
void				ft_print_width_str(t_fps *format_str, int max,
										int len_we_print);

/*
** int
*/

int					if_int(int i, t_fps *format_str);
void				ft_chek_flags_int(char *int_str, int save_i,
										t_fps *format_str);
void				ft_print_int(char *int_str, int save_i, t_fps *format_str);
void				ft_width_int(t_fps *format_str, int max,
								int len_int, int null);
int					ft_check_negative_plus_whirespase(t_fps *format_str, int i,
														int *if_minint);

/*
** persent
*/

void				if_percent(t_fps *format_str);

/*
** pointer
*/

int					if_pointer(unsigned long long pn, t_fps *format_str);
void				ft_print_pointer(char *pointer, t_fps *format_str);
void				ft_width_pointer(t_fps *format_str, int max,
									int len_pn, int null);

/*
** undigned int
*/

void				if_unsint(unsigned int unsint, t_fps *format_str);
void				ft_width_unsint(t_fps *format_str, int max,
									int len_unsint, int null);
void				ft_chek_flags_unsint(char *unsint_str, t_fps *format_str);
void				ft_print_unsint(char *unsint_str, t_fps *format_str);

/*
** hexadecimal
*/

int					if_hexadecimal_x(unsigned int unsint, t_fps *format_str);
void				if_hexadecimal(unsigned int unsint, t_fps *format_str);
void				ft_chek_flags_hexadecimal(char *hexa_str,
											t_fps *format_str, int x);
void				ft_print_hexadecial(char *hexa_str, t_fps *format_str,
										int len_hexa, int x);
void				ft_width_hexadecimal(t_fps *format_str, int max,
								int len_unsint, int null);

/*
** additional function
*/

char				*ft_itoa_hexadecimal(unsigned int n);
char				*ft_itoa_pointer(unsigned long long n);
size_t				ft_numsize_p(unsigned long long n);
size_t				ft_numsize_h_u(unsigned int n, int base);
char				*ft_itoa_unsint(unsigned int n);

#endif
