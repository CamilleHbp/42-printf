/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:00:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 16:42:28 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_fraction(t_double fraction, t_format format, t_buffer *buffer)
{
	t_unsigned fraction_unsigned;

	buffered_print(".", 1, buffer);
	if (fraction.nb == 0.0)
	{
		while (format.precision--)
			buffered_print("0", 1, buffer);
		return ;
	}
	if (format.precision)
	{
		while (fraction.nb < 0.1 && format.precision--)
		{
			buffered_print("0", 1, buffer);
			fraction.nb *= fraction.base;
		}
		while (format.precision--)
			fraction.nb *= fraction.base;
		fraction_unsigned.nb = ft_round(fraction.nb);
		fraction_unsigned.base = fraction.base;
		buffer_itoa_base(fraction_unsigned, format, buffer);
	}
}

int32_t	is_denormalized(long double nb, t_format format, t_buffer *buffer)
{
	uint64_t	raw_value;
	double		nbd;

	nbd = (double)nb;
	raw_value = *(uint64_t *)&nbd;
	if (((raw_value >> 52) & 0xFFF) == 0xFFF)
	{
		if (raw_value & 0x000FFFFFFFFFFFFF)
			buffered_print((format.flags & UPPER) ? "-NAN" : "-nan", 4, buffer);
		else
			buffered_print((format.flags & UPPER) ? "-INF" : "-inf", 4, buffer);
		return (SUCCESS);
	}
	else if (((raw_value >> 52) & 0xFFF) == 0x7FF)
	{
		if (raw_value & 0x000FFFFFFFFFFFFF)
			buffered_print((format.flags & UPPER) ? "NAN" : "nan", 3, buffer);
		else
			buffered_print((format.flags & UPPER) ? "INF" : "inf", 3, buffer);
		return (SUCCESS);
	}
	return (FAILURE);
}
