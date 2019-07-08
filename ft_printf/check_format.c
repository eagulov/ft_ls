/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:30:49 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/15 15:53:54 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*my_argnew(void)
{
	t_arg	*new;

	new = (t_arg *)ft_memalloc(sizeof(t_arg));
	new->width = 0;
	new->precisn = 0;
	new->length = NULL;
	return (new);
}

int		construct(char **dest, int destlen, char *orig, int size)
{
	int		length;
	char	*tmp;

	length = destlen + size;
	tmp = ft_strnew(length);
	if (*dest)
		ft_strncpy(tmp, *dest, destlen);
	ft_strncpy(tmp + destlen, orig, size);
	ft_memdel((void **)dest);
	*dest = tmp;
	return (size);
}

int		parse_format(char **format, va_list *list, char **finalstr,
														int finallen)
{
	t_arg	*args;

	args = my_argnew();
	parse_flags(format, args);
	parse_width(format, args, list);
	parse_precisn(format, args, list);
	parse_length(format, args);
	parse_specifier(format, args);
	return ((logic(list, args, finalstr, finallen)));
}

int		check_format(char *format, va_list *list)
{
	char			*cur_char;
	int				res;
	char			*finalstr;

	finalstr = NULL;
	res = 0;
	while ((cur_char = ft_strchr(format, '%')))
	{
		res += construct(&finalstr, res, format, cur_char - format);
		format = cur_char + 1;
		if (*format)
			res += parse_format(&format, list, &finalstr, res);
	}
	if (*format)
		res += construct(&finalstr, res, format, ft_strlen(format));
	write(1, finalstr, res);
	ft_strdel(&finalstr);
	return (res);
}
