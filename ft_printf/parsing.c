/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:24:17 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/15 15:56:35 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(char **format, t_arg *ar)
{
	ar->specifier = **format;
	if ((ar->specifier == 'f' || ar->specifier == 'F') && ar->precisn == -1)
		ar->precisn = 6;
	if (ar->specifier == 'O')
	{
		if (ar->length)
			ft_strdel(&ar->length);
		ar->length = ft_strdup("l");
	}
	if (ar->specifier == 'D')
	{
		if (ar->length)
			ft_strdel(&ar->length);
		ar->length = ft_strdup("l");
	}
	if (ar->specifier == 'F')
	{
		if (ar->length)
			ft_strdel(&ar->length);
		ar->length = ft_strdup("L");
	}
	if (get_funcs(ar->specifier))
		(*format)++;
}

void	parse_length(char **format, t_arg *args)
{
	char	*first_length;

	first_length = *format;
	while (**format == 'l' || **format == 'h' ||
			**format == 'j' || **format == 'z' || **format == 'L')
		(*format)++;
	if (args->length)
		ft_strdel(&args->length);
	args->length = ft_strsub(first_length, 0, *format - first_length);
}

void	parse_precisn(char **format, t_arg *args, va_list *list)
{
	if (**format != '.')
	{
		args->precisn = -1;
		return ;
	}
	else
		(*format)++;
	if (**format == '*')
	{
		args->precisn = va_arg(*list, int);
		(*format)++;
	}
	else
		args->precisn = ft_atoi(*format);
	while ((**format >= '0' && **format <= '9')
			|| **format == '+' || **format == '-')
		(*format)++;
	if (args->precisn < 0)
		args->precisn = -1;
}

void	parse_width(char **format, t_arg *args, va_list *list)
{
	if (**format != '*' && !(**format >= '0' && **format <= '9'))
		return ;
	args->width = ft_atoi(*format);
	while ((**format >= '0' && **format <= '9'))
		(*format)++;
	if (**format == '*')
	{
		args->width = va_arg(*list, int);
		args->width *= (args->width < 0 && (args->flag.left_jstfed = 1)) ? \
						-1 : 1;
		(*format)++;
		parse_width(format, args, list);
	}
}

void	parse_flags(char **format, t_arg *args)
{
	while (**format == ' ' || **format == '#' || **format == '0'
						|| **format == '-' || **format == '+')
	{
		if (**format == ' ')
			args->flag.space = true;
		if (**format == '#')
			args->flag.hash = true;
		if (**format == '0')
			args->flag.zero = true;
		if (**format == '-')
			args->flag.left_jstfed = true;
		if (**format == '+')
			args->flag.force_sign = true;
		(*format)++;
	}
}
