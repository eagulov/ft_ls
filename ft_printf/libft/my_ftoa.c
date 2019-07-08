/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:52:39 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/18 15:58:03 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_smaller_ftoa(char *floatpart, int precisn, int iszero)
{
	char		*answer;
	int			length;

	if (iszero && precisn == 0)
	{
		length = 1;
		answer = ft_strnew(length);
		answer[0] = '0';
	}
	else if (iszero)
	{
		length = precisn + 2;
		answer = ft_strnew(length);
		ft_strncpy(answer, "0.", 2);
		ft_memset(answer + 2, '0', precisn);
	}
	else
	{
		length = ft_strlen(floatpart);
		answer = ft_strnew(length + 2);
		ft_strncpy(answer, "0.", 2);
		ft_strncpy(answer + 2, floatpart, length);
	}
	ft_strdel(&floatpart);
	return (answer);
}

char			*my_ftoa(long double number, int precisn)
{
	char	*str;
	char	*answer;
	int		smaller;
	int		intprtsize;

	intprtsize = my_nbsize((long long int)number);
	smaller = (number > -1 && number < 1);
	while (number != 0 && precisn > 0 && precisn--)
		number *= 10;
	if (((long long int)(number * 10) % 10) >= 5)
		((long long int)number > 0) ? number++ : number--;
	str = my_ltoa((long long int)number, 10);
	if (smaller)
		return (get_smaller_ftoa(str, precisn, number == 0));
	else
		answer = ft_strnew(my_nbsize((long long int)number) + 1);
	ft_memcpy(answer, str, intprtsize);
	if (ft_strlen(str + intprtsize))
		answer[intprtsize] = '.';
	ft_memcpy(answer + intprtsize + 1, str + intprtsize,
												ft_strlen(str + intprtsize));
	ft_strdel(&str);
	return (answer);
}
