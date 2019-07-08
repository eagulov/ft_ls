/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:35:02 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/27 18:11:13 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_dectohex(unsigned long long int num)
{
	char	arr[32];
	char	*ans;
	int		remainder;
	int		counter;

	counter = 0;
	ft_bzero(arr, 32);
	ans = ft_strnew(32);
	if (num == 0)
		arr[counter++] = '0';
	while (num)
	{
		remainder = num % 16;
		if (remainder < 10)
			arr[counter++] = remainder + 48;
		else
			arr[counter++] = remainder + 87;
		num /= 16;
	}
	ans = ft_strcpy(ans, my_strrev(arr));
	return (ans);
}
