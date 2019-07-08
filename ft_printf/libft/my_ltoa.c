/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:23:39 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/13 18:08:52 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_ltoa(unsigned long n, int base)
{
	char			*tail;
	char			*head;
	char			*buf;
	unsigned long	rem;
	int				counter;

	if (base < 2 || base > 36)
		base = 10;
	buf = ft_strnew(sizeof(long) * 8 + 1);
	tail = &buf[sizeof(long) * 8];
	head = buf;
	if (!n)
		*tail-- = '0';
	counter = 1;
	while (n)
	{
		rem = n % base;
		*tail-- = (char)(rem + ((9L < rem) ? ('a' - 10L) : '0'));
		n /= base;
		counter++;
	}
	ft_memcpy(head, ++tail, counter);
	head = ft_strdup(head);
	ft_memdel((void **)&buf);
	return (head);
}
