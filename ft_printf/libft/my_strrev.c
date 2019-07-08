/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:44:32 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/26 08:49:23 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_strrev(const char *str)
{
	char	*start;
	char	*end;
	char	temp;
	int		length;

	start = (char *)str;
	end = start;
	while (*(end + 1))
		end++;
	length = (end - start + 1) / 2;
	while (length--)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
	return ((char *)str);
}
