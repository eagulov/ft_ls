/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:46:19 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/11 18:32:53 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_get_char(t_arg *args, va_list *list, int *len)
{
	char *str;

	*len = !args->width ? 1 : args->width;
	str = ft_strnew(*len);
	str = ft_memset(str, ' ', args->width);
	if (args->flag.left_jstfed)
		str[0] = args->specifier == '%' ? '%' : va_arg(*list, int);
	else
		str[*len - 1] = args->specifier == '%' ? '%' : va_arg(*list, int);
	return (str);
}
