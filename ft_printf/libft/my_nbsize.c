/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_nbsize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:56:05 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/08 16:59:51 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		my_nbsize(long long int number)
{
	int	answer;

	answer = 1;
	while (number /= 10)
		answer++;
	return (answer);
}
