/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 17:36:50 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/07 17:37:16 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_strlower(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr)
	{
		if (my_isletter(*ptr) && (my_iscapital(*ptr)))
			*ptr += 32;
		ptr++;
	}
	return (str);
}
