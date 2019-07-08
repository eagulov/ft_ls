/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:49:58 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/15 14:41:40 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_fill_data(char *dest, t_arg *args, int zeros, char *src)
{
	if (args->flag.hash && *src != '0')
		dest = ft_strncpy(dest, "0x", 2) + 2;
	while (zeros--)
		*dest++ = '0';
	if (*src == '0' && !args->precisn)
		return ;
	dest = ft_strncpy(dest, src, ft_strlen(src));
}

char		*pf_get_hex(t_arg *ar, va_list *list, int *len)
{
	char	*str;
	char	*answer;
	int		actlen;
	int		zeros;

	str = my_ltoa(conversion_unsigned(ar, list), 16);
	actlen = (*str == '0' && !ar->width && !ar->precisn) ? 0 : ft_strlen(str);
	zeros = ar->precisn < actlen ? 0 : ar->precisn - actlen;
	actlen += ((ar->flag.hash && *str != '0') ? 2 : 0) + zeros;
	*len = ar->width < actlen ? actlen : ar->width;
	if (ar->flag.zero && !ar->flag.left_jstfed)
		zeros = *len - actlen;
	answer = ft_strnew(*len);
	answer = ft_memset(answer, ' ', *len);
	if (ar->flag.left_jstfed || ar->flag.zero)
		pf_fill_data(answer, ar, zeros, str);
	else
		pf_fill_data(answer + (*len - actlen), ar, zeros, str);
	ft_strdel(&str);
	return (answer);
}

char		*pf_hex_wrapper(t_arg *args, va_list *list, int *len)
{
	return (my_strupper(pf_get_hex(args, list, len)));
}
