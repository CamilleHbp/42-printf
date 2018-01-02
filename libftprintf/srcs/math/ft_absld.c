/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absld.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 13:56:00 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 14:25:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** By casting the value using the adress, we get the internal bit reprensation
** not the converted value in integer.
*/

long double	ft_absld(long double x)
{
	uintmax_t	casted;

	if (sizeof(long double) == 8)
	{
		casted = *(uintmax_t*) &x;
		casted &= 0x7FFFFFFFFFFFFFFF;
		return *(long double*)&casted;
	}
	else
		return ((x < 0) ? -x : x);
}
