/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:29:55 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/15 14:41:23 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*pf_fill_data(char *dest, t_arg *args, t_meta meta)
{
	ft_strncpy(dest, "0x", 2);
	ft_memset(dest + 2, '0', meta.zeros);
	if (!(args->precisn == 0 && meta.value[0] == '0'))
		ft_strncpy(dest + 2 + meta.zeros, meta.value, meta.actlen - 2);
	return (dest);
}

char			*pf_get_addr(t_arg *ar, va_list *list, int *len)
{
	t_meta	m;
	char	*answer;
	int		index;

	m.value = my_ltoa(va_arg(*list, unsigned long), 16);
	m.actlen = (ar->precisn == 0 && m.value[0] == '0') ? \
							2 : ft_strlen(m.value) + 2;
	m.zeros = ar->precisn < m.actlen ? 0 : ar->precisn - m.actlen;
	*len = ar->width > m.actlen ? ar->width : m.actlen;
	index = (ar->flag.left_jstfed) ? 0 : *len - m.actlen;
	answer = ft_strnew(*len);
	answer = ft_memset(answer, ' ', *len);
	pf_fill_data(answer + index, ar, m);
	ft_strdel(&m.value);
	return (my_strlower(answer));
}
