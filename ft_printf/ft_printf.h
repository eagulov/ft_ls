/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:18:25 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/15 14:25:02 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <wchar.h>

# define CONV_TO_CHR(x) x ? unsigned char : char
# define CONV_TO_SHRT(x) x ? unsigned short : short
# define CONV_TO_L(x) x ? unsigned long : long
# define CONV_TO_LL(x) x ? unsigned long long : long long
# define CONV_TO_J(x) x ? uintmax_t : intmax_t

# define FRONT_SPACE(x, y) x.isneg || y->flag.force_sign || y->flag.space

typedef struct		s_flags
{
	bool			left_jstfed;
	bool			zero;
	bool			hash;
	bool			force_sign;
	bool			space;
}					t_flags;

typedef struct		s_arg
{
	int				width;
	int				precisn;
	char			*length;
	char			specifier;
	char			sign;
	int				len;
	t_flags			flag;
}					t_arg;

typedef	struct		s_metadata
{
	int				actlen;
	int				isneg;
	int				zeros;
	char			*value;
}					t_meta;

typedef char* (*t_func)(t_arg*, va_list*, int *len);

int					ft_printf(const char *format, ...);
int					construct(char **dest, int destlen, char *orig, int size);
int					check_format(char *format, va_list *list);
void				parse_flags(char **format, t_arg *args);
void				parse_width(char **format, t_arg *args, va_list *list);
void				parse_precisn(char **format, t_arg *args, va_list *list);
void				parse_length(char **format, t_arg *args);
void				parse_specifier(char **format, t_arg *args);
t_func				get_funcs(char c);
int					logic(va_list *list, t_arg *args, char **finalstr,
																int finallen);
char				*pf_get_float(t_arg *args, va_list *list, int *len);
char				*pf_get_number(t_arg *args, va_list *list, int *len);
char				*pf_get_unumber(t_arg *args, va_list *list, int *len);
char				*pf_get_char(t_arg *args, va_list *list, int *len);
char				*pf_get_str(t_arg *args, va_list *list, int *len);
char				*pf_get_wstr(t_arg *args, va_list *list, int *len);
char				*pf_get_octal(t_arg *args, va_list *list, int *len);
char				*pf_octal_wrapper(t_arg *args, va_list *list, int *len);
char				*pf_get_hex(t_arg *args, va_list *list, int *len);
char				*pf_hex_wrapper(t_arg *args, va_list *list, int *len);
char				*pf_get_addr(t_arg *args, va_list *list, int *len);
char				*pf_get_binary(t_arg *args, va_list *list, int *len);
long				conversion_signed(t_arg *args, va_list *list);
unsigned long		conversion_unsigned(t_arg *args, va_list *list);

#endif
