/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 07:57:50 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/08 19:25:50 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_get_binary(t_arg *args, va_list *list, int *len)
{
	char	*str;
	int		actlen;
	int		index;
	int		zeros;
	char	*answer;

	str = my_get_binary(va_arg(*list, unsigned long));
	actlen = ft_strlen(str);
	zeros = args->precisn < actlen ? 0 : args->precisn - actlen;
	*len = args->width > actlen + zeros ? args->width : actlen + zeros;
	answer = ft_strnew(*len);
	ft_memset(answer, ' ', *len);
	index = args->flag.left_jstfed ? 0 : *len - (actlen + zeros);
	while (zeros--)
		answer[index++] = '0';
	ft_memcpy(answer + index, str, actlen);
	ft_strdel(&str);
	return (answer);
}
