/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:35:43 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/18 15:54:57 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_handle_sign(char *ans, int *index, t_meta m, t_arg *ar)
{
	if ((ar->flag.force_sign || ar->flag.space) && !m.isneg)
	{
		*index -= (!ar->flag.zero && *index - 1 > 0) ? 1 : 0;
		ans[ar->flag.zero ? 0 : (*index)++] = ar->flag.force_sign ? '+' : ' ';
	}
	else if (m.isneg)
	{
		*index -= (!ar->flag.zero && *index - 1 > 0) ? 1 : 0;
		ans[ar->flag.zero ? 0 : (*index)++] = '-';
	}
}

char		*pf_get_float(t_arg *ar, va_list *list, int *len)
{
	char		*answer;
	t_meta		m;
	int			index;
	long double	num;

	num = (ar->length && ar->length[0] == 'L') ? \
			va_arg(*list, long double) : va_arg(*list, double);
	num *= (num < 0 && (m.isneg = 1)) ? -1 : 1;
	m.isneg = (m.isneg == 1) ? 1 : 0;
	m.value = my_ftoa(num, ar->precisn);
	m.actlen = FRONT_SPACE(m, ar) ? ft_strlen(m.value) + 1 : ft_strlen(m.value);
	*len = ar->width > m.actlen ? ar->width : m.actlen;
	answer = ft_strnew(*len);
	ft_memset(answer, ar->flag.zero && !ar->flag.left_jstfed ? '0' : ' ', *len);
	index = ar->flag.left_jstfed ? 0 : *len - m.actlen;
	pf_handle_sign(answer, &index, m, ar);
	if (ar->precisn == 0 && ar->flag.hash && num != 0)
		*(answer + (--index) + m.actlen) = '.';
	ft_memcpy(answer + index, m.value, m.isneg ? m.actlen - 1 : m.actlen);
	ft_strdel(&m.value);
	return (answer);
}
