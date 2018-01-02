/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common_floats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:23:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/02 17:55:12 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static void	print_decimal(long double nb, uint8_t base, t_format format,
			t_buffer *buffer)
{
	while (format.precision > 0)
	{
		nb *= base;
		if (nb == 0)
			buffered_print("0", 1 , buffer);
		format.precision--;
	}
	if (nb != 0)
		print_itoa_base(ft_round(nb), base, format, buffer);
}

static void	print_exponent(int64_t exponent, uint8_t base, t_format format,
			t_buffer *buffer)
{
	if (base == 16)
	{
		if (format.flags & UPPERCASE)
			buffered_print("P", 1, buffer);
		else
			buffered_print("p", 1, buffer);
	}
	else
	{
		if (format.flags & UPPERCASE)
			buffered_print("E", 1, buffer);
		else
			buffered_print("e", 1, buffer);
	}
	if (exponent >= 0)
		buffered_print("+", 1 , buffer);
	else
		buffered_print("-", 1 , buffer);
	if ((exponent < 9) && (exponent > -9))
		buffered_print("0", 1 , buffer);
	print_itoa_base(ft_absl(exponent), 10, format, buffer);
}

static void	return_parts(uint64_t *integer, long double *decimal,
				int64_t *exponent, uint8_t base, long double nb)
{
	*integer = 0;
	*decimal = 0.0;
	*exponent = 0;
	// Divide the number until we have only one digit left
	if (nb == 0)
		return;
	else if (nb >= 1)
	{
		while (nb > (base - 1))
		{
			nb /= base;
			*exponent += 1;
		}
	}
	// We get the integer and decimal part and calculate the decimal len for the precision
	else if (nb < 1)
	{
		while (nb < 1)
		{
			nb *= base;
			*exponent -= 1;
		}
	}
	*integer = (uint64_t)nb;
	*decimal = nb - *integer;
}

void		print_float_number(long double nb, uint8_t base, t_format format,
			t_buffer *buffer)
{
	int64_t	integer;
	long double decimal;

	// We get the integer and decimal part and calculate the decimal len for the precision
	integer = ft_absld(nb);
	decimal = ft_absld(nb) - integer;
	// If no precision is specified, it is 6
	if (!(format.flags & PRECISION))
		format.precision = 6;
	// first we need to calculate the total width needed
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	// If the format precision is not 0, we need to subtract 1 more for the '.'
	format.width -= get_nb_len(ft_absl(integer), base);
	format.width -= (format.precision == 0) ? 0 : format.precision + 1;
	// If we need to right justify, and pad with spaces, we do before the prefix
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width, buffer);
	if (nb < 0)
		buffered_print("-", 1, buffer);
	// If we need to right justify, and pad with 0, we do that after the prefix
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD))
		padd_value("0", format.width, buffer);
	// If precision is 0, we print only the rounded integer part
	if (format.precision == 0)
		print_itoa_base(ft_absl(ft_round(nb)), base, format, buffer);
	// We print the integer part then the point, then the decimal part
	else
	{
		print_itoa_base(integer, base, format, buffer);
		buffered_print(".", 1, buffer);
		print_decimal(decimal, base, format, buffer);
	}
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}

// DEBUG:
#include <stdio.h>
void		print_float_scientific(long double nb, uint8_t base, char *prefix,
			t_format format, t_buffer *buffer)
{
	uint64_t	integer;
	int64_t	exponent;
	long double decimal;

	return_parts(&integer, &decimal, &exponent, base, ft_absld(nb));
	// If no precision is specified, it is 6
	if (!(format.flags & PRECISION))
		format.precision = 6;
	// first we need to calculate the total width needed
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	// If the format precision is not 0, we need to subtract 1 more for the '.'
	format.width -= get_nb_len(ft_absl(integer), base);
	format.width -= (format.precision == 0) ? 0 : format.precision + 1;
	// If we need to right justify, and pad with spaces, we do before the prefix
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width, buffer);
	if (nb < 0)
		buffered_print("-", 1, buffer);
	// If we are in hexa, we need to print the prefix
	buffered_print(prefix, ft_strlen(prefix), buffer);
	// If we need to right justify, and pad with 0, we do that after the prefix
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD))
		padd_value("0", format.width, buffer);
	// If precision is 0, we print only the rounded integer part
	if (format.precision == 0)
		print_itoa_base(ft_absl(ft_round(nb)), base, format, buffer);
	// We print the integer part then the point, then the decimal part
	else
	{
		print_itoa_base(integer, base, format, buffer);
		buffered_print(".", 1, buffer);
		print_decimal(decimal, base, format, buffer);
	}
	print_exponent(exponent, base, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}
