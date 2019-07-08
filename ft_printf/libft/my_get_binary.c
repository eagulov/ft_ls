/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_get_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 07:46:13 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/08 19:21:45 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_get_binary(unsigned long octet)
{
	unsigned long	i;
	int				size;
	int				counter;
	char			*res;

	counter = octet;
	size = 0;
	while (counter)
	{
		size++;
		counter >>= 1;
	}
	res = ft_strnew(size);
	counter = 0;
	i = 1;
	while (i <= octet)
	{
		res[counter++] = i & octet ? '1' : '0';
		i <<= 1;
	}
	return (my_strrev(res));
}
