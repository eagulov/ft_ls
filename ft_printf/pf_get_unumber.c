/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_unumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:23:49 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/14 17:24:15 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*fill_data(t_arg *args, t_meta m, int size)
{
	char	*answer;
	int		i;

	i = 0;
	answer = ft_strnew(size);
	answer = ft_memset(answer, ' ', size);
	i = args->flag.left_jstfed ? 0 : size - (m.actlen + m.zeros);
	while (m.zeros--)
		answer[i++] = '0';
	ft_memcpy(answer + i, m.value, m.actlen);
	return (answer);
}

char			*pf_get_unumber(t_arg *ar, va_list *list, int *len)
{
	char			*answer;
	t_meta			mt;
	unsigned long	num;

	num = conversion_unsigned(ar, list);
	mt.value = my_ltoa(num, 10);
	mt.actlen = (!ar->precisn && num == 0) ? 0 : ft_strlen(mt.value);
	mt.zeros = ar->precisn < mt.actlen ? 0 : ar->precisn - mt.actlen;
	*len = ar->width > (mt.actlen + mt.zeros) ? ar->width \
						: (mt.actlen + mt.zeros);
	if (ar->flag.zero && !ar->flag.left_jstfed)
		mt.zeros = *len - mt.actlen;
	answer = fill_data(ar, mt, *len);
	ft_strdel(&mt.value);
	return (answer);
}
