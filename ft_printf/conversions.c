/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:21:56 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/14 14:38:02 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long			conversion_signed(t_arg *args, va_list *list)
{
	if (args->length[0] == '\0')
		return (va_arg(*list, int));
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		return ((char)va_arg(*list, int));
	else if (args->length[0] == 'h')
		return ((short int)va_arg(*list, int));
	else if (args->length[0] == 'l' && args->length[1] == 'l')
		return ((va_arg(*list, long long int)));
	else if (args->length[0] == 'l')
		return ((va_arg(*list, long int)));
	else if (args->length[0] == 'j')
		return (va_arg(*list, intmax_t));
	else
		return (va_arg(*list, size_t));
}

unsigned long	conversion_unsigned(t_arg *args, va_list *list)
{
	if (args->specifier == 'U')
		return (va_arg(*list, unsigned long int));
	if (args->length[0] == '\0')
		return (va_arg(*list, unsigned int));
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		return ((unsigned char)va_arg(*list, unsigned int));
	else if (args->length[0] == 'h')
		return ((unsigned short)va_arg(*list, unsigned int));
	else if (args->length[0] == 'l' && args->length[1] == 'l')
		return ((va_arg(*list, unsigned long long int)));
	else if (args->length[0] == 'l')
		return ((va_arg(*list, unsigned long int)));
	else if (args->length[0] == 'j')
		return (va_arg(*list, uintmax_t));
	else
		return (va_arg(*list, size_t));
}
