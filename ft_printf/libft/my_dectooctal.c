/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dectooctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 10:25:21 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/27 18:12:54 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_dectooctal(unsigned long long int num)
{
	char	arr[32];
	char	*asw;
	int		counter;

	counter = 0;
	ft_bzero(arr, 32);
	asw = ft_strnew(32);
	if (num == 0)
		arr[counter++] = '0';
	while (num)
	{
		arr[counter++] = num % 8 + 48;
		num /= 8;
	}
	asw = ft_strcpy(asw, my_strrev(arr));
	return (asw);
}
