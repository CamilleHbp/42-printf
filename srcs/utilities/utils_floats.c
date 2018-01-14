/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:00:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/10 21:04:20 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_fraction(long double fraction, uint8_t base, t_format format,
						  t_buffer *buffer)
{
	buffered_print(".", 1, buffer);
	if (fraction == 0.0)
	{
		while(format.precision--)
			buffered_print("0", 1, buffer);
		return ;
	}
	if (format.precision)
	{
		while (fraction < 0.1 && format.precision--)
		{
			buffered_print("0", 1, buffer);
			fraction *= base;
		}
		while (format.precision--)
			fraction *= base;
		buffer_itoa_base(ft_round(fraction), base, format, buffer);
	}
}

#include <stdio.h>
int32_t	is_denormalized(long double nb, t_format format, t_buffer *buffer)
{
	uint64_t	raw_value;
	double		nbd;

	nbd = (double)nb;
	raw_value = *(uint64_t *)&nbd;
	if (((raw_value >> 52) & 0xFFF) == 0xFFF)
	{
		if (raw_value & 0x000FFFFFFFFFFFFF)
			buffered_print(
				(format.flags & UPPERCASE) ? "-NAN" : "-nan", 4, buffer);
		else
			buffered_print(
				(format.flags & UPPERCASE) ? "-INF" : "-inf", 4, buffer);
		return (SUCCESS);
	}
	else if (((raw_value >> 52) & 0xFFF) == 0x7FF)
	{
		if (raw_value & 0x000FFFFFFFFFFFFF)
			buffered_print(
				(format.flags & UPPERCASE) ? "NAN" : "nan", 3, buffer);
		else
			buffered_print(
				(format.flags & UPPERCASE) ? "INF" : "inf", 3, buffer);
		return (SUCCESS);
	}
	return (FAILURE);
}
