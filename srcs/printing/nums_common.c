/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:22 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 18:07:07 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"
#include <stdio.h>

static void	print_signed_prefix(intmax_t nb, t_format format, t_buffer *buffer)
{
	if (nb < 0)
		buffered_print("-", 1, buffer);
	else if ((format.flags & SIGN))
		buffered_print("+", 1, buffer);
	else if ((format.flags & SPACE))
		buffered_print(" ", 1, buffer);
}

static void	print_unsigned_prefix(uintmax_t nb, uint8_t base, char *prefix,
				t_format format, t_buffer *buffer)
{
	if ((nb != 0) || (format.flags & POINTER) || base == 8)
	{
		if (format.flags & PREFIX)
			buffered_print(prefix, ft_strlen(prefix), buffer);
	}
}

	// If we have a 0 number and a precision of 0, we need to add 1 as we won't display the number
static int32_t calculate_width(uintmax_t nb, int8_t sign, uint8_t base,
			char *prefix, t_format format)
{
	if ((sign < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	format.width -= (format.flags & PREFIX) ? ft_strlen(prefix) : 0;
	format.width -= ft_max(format.precision, get_nb_len(nb, base));
	if ((nb == 0) && (format.flags & PRECISION) && (format.precision == 0))
		format.width += 1;
	return (format.width);
}

	// first we need to calculate the total width needed
	// If we need to right justify, and pad with spaces, we do before the prefix
	// if the number is 0 and we have a precision of 0, we only need to pad
	// If we need to right justify, and pad with 0, we do that after the prefix
	// We print the necessary 0 padding
void	print_signed(intmax_t nb, uint8_t base, char *prefix, t_format format,
			t_buffer *buffer)
{
	size_t	leftover;

	format.width = calculate_width(ft_absl(nb), (nb < 0) ? -1 : 1, base, prefix,
					format);
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width, buffer);
	if (nb == 0 && (format.precision == 0))
		return ;
	print_signed_prefix(nb, format, buffer);
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD)
			&& !(format.flags & PRECISION))
		padd_value("0", format.width, buffer);
	leftover = format.precision - get_nb_len(ft_absl(nb), base);
	padd_value("0", leftover, buffer);
	print_itoa_base(ft_absl(nb), base, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}

	// first we need to calculate the total width needed
	// If we need to right justify, and pad with spaces, we do before the prefix
	// If we need to right justify, and pad with 0, we do that after the prefix
	// We print the necessary 0 padding
	// if the number is 0 and we have a precision of 0, we only need to pad
void	print_unsigned(uintmax_t nb, uint8_t base, char *prefix, t_format format,
			t_buffer *buffer)
{
	size_t	leftover;

	format.width = calculate_width(nb, 1, base, prefix, format);
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width, buffer);
	print_unsigned_prefix(nb, base, prefix, format, buffer);
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD)
			&& !(format.flags & PRECISION))
		padd_value("0", format.width, buffer);
	leftover = format.precision - get_nb_len(nb, base);
	padd_value("0", leftover, buffer);
	if (!(nb == 0 && format.precision <= 0) || base == 8)
		print_itoa_base(nb, base, format, buffer);
	// else if (format.width != 0)
			// buffered_print(" ", 1, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}
