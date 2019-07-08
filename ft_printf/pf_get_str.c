/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 10:50:06 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/15 15:47:50 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_get_str(t_arg *args, va_list *list, int *len)
{
	char	*str;
	char	*answer;
	int		actlen;
	int		prec;

	str = va_arg(*list, char *);
	if (!str)
	{
		*len += ((answer = ft_strdup("(null)"))) ? 6 : 6;
		return (answer);
	}
	actlen = ft_strlen(str);
	*len = (args->precisn != -1 && args->precisn < actlen) ? \
			args->precisn : actlen;
	*len = (*len < args->width) ? args->width : *len;
	answer = ft_strnew(*len);
	answer = ft_memset(answer, ' ', *len);
	prec = (args->precisn != -1 && args->precisn < actlen) ? \
			args->precisn : actlen;
	if (args->flag.left_jstfed)
		ft_memcpy(answer, str, prec);
	else
		ft_memcpy(answer + (*len - prec), str, prec);
	return (answer);
}
