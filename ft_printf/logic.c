/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:07:08 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/15 15:58:34 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_funcs(t_func *func)
{
	func['%'] = &pf_get_char;
	func['c'] = &pf_get_char;
	func['C'] = &pf_get_char;
	func['s'] = &pf_get_str;
	func['i'] = &pf_get_number;
	func['d'] = &pf_get_number;
	func['D'] = &pf_get_number;
	func['U'] = &pf_get_unumber;
	func['u'] = &pf_get_unumber;
	func['b'] = &pf_get_binary;
	func['f'] = &pf_get_float;
	func['F'] = &pf_get_float;
	func['p'] = &pf_get_addr;
	func['o'] = &pf_get_octal;
	func['O'] = &pf_octal_wrapper;
	func['x'] = &pf_get_hex;
	func['X'] = &pf_hex_wrapper;
	func['S'] = &pf_get_str;
}

t_func			get_funcs(char c)
{
	static t_func	*func;

	if (!func)
	{
		func = ft_memalloc(sizeof(*func) * 256);
		if (func)
			init_funcs(func);
	}
	return (func[(int)c]);
}

int				logic(va_list *list, t_arg *args, char **finalstr, int finallen)
{
	t_func	function;
	char	*value;
	int		valuelen;

	function = get_funcs(args->specifier);
	valuelen = 0;
	if (function)
	{
		value = function(args, list, &valuelen);
		valuelen = construct(finalstr, finallen, value, valuelen);
		ft_strdel(&value);
	}
	if (args->length)
		ft_strdel(&args->length);
	ft_memdel((void **)&args);
	return (valuelen);
}
