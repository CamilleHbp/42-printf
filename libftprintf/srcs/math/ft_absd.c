/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 23:15:37 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 13:47:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** By casting the value using the adress, we get the internal bit reprensation
** not the converted value in integer.
*/

double	ft_absd(double x)
{
	uint64_t casted;

	casted = *(uint64_t*) &x;
	casted &= 0x7FFFFFFFFFFFFFFF;
	return *(double*)&casted;
}
