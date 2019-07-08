/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:16:17 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/14 16:13:14 by eagulov          ###   ########.fr       */
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
	if (m.isneg)
		answer[i++] = '-';
	else if (args->flag.force_sign || args->flag.space)
		answer[i++] = args->flag.force_sign ? '+' : ' ';
	while (m.zeros--)
		answer[i++] = '0';
	if (args->precisn == 0 && m.value[0] == '0')
		return (answer);
	ft_memcpy(answer + i, m.value, ft_strlen(m.value));
	return (answer);
}

char			*pf_get_number(t_arg *ar, va_list *list, int *len)
{
	char	*answer;
	t_meta	mt;
	long	num;

	mt.isneg = 0;
	num = conversion_signed(ar, list);
	num *= (num < 0 && (mt.isneg = 1)) ? -1 : 1;
	mt.value = my_ltoa(num, 10);
	mt.actlen = (!ar->precisn && num == 0) ? 0 : ft_strlen(mt.value);
	mt.zeros = ar->precisn < mt.actlen ? 0 : ar->precisn - mt.actlen;
	if (mt.isneg)
		mt.actlen++;
	if (((ar->flag.force_sign || ar->flag.space) && !mt.isneg))
		mt.actlen += 1;
	*len = ar->width > (mt.actlen + mt.zeros) ? ar->width \
						: (mt.actlen + mt.zeros);
	if (ar->flag.zero && !ar->flag.left_jstfed)
		mt.zeros = ar->precisn > 0 ? *len - ar->precisn : *len - mt.actlen;
	answer = fill_data(ar, mt, *len);
	ft_strdel(&mt.value);
	return (answer);
}
