/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 08:27:15 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/27 09:04:27 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_strupper(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr)
	{
		if (my_isletter(*ptr) && !(my_iscapital(*ptr)))
			*ptr -= 32;
		ptr++;
	}
	return (str);
}
