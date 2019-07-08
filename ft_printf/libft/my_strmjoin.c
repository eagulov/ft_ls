/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:06:57 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/26 08:05:08 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_strmjoin(int num, ...)
{
	va_list	ap;
	char	*res;
	char	*tmp;
	char	*arg;

	res = ft_strnew(0);
	va_start(ap, num);
	while (num--)
	{
		arg = va_arg(ap, char *);
		tmp = res;
		res = ft_strjoin(tmp, arg);
		ft_memdel((void **)&tmp);
	}
	va_end(ap);
	return (res);
}
