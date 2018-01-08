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
	else if (format.flags & SIGN)
		buffered_print("+", 1, buffer);
	else if (format.flags & SPACE)
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
static int32_t signed_width(intmax_t nb, t_format format)
{
	int32_t		to_print;
	intmax_t	tmp;

	to_print = 0;
	tmp = ft_absl(nb);
	while (tmp > 0)
	{
		tmp /= 10;
		++to_print;
	}
	to_print = ft_max(to_print, format.precision);
	if (nb < 0 || format.flags & SIGN || format.flags & SPACE)
		++to_print;
	return (to_print);
}

static int32_t unsigned_width(uintmax_t nb, uint8_t base, char *prefix,
					t_format format)
{
	int32_t		to_print;
	uintmax_t	tmp;

	to_print = 0;
	tmp = nb;
	while (tmp > 0)
	{
		tmp /= 10;
		++to_print;
	}
	if (base == 8 && format.flags & PREFIX)
		(format.precision < to_print) ? (format.precision = to_print + 1) : 0;
	to_print = ft_max(to_print, format.precision);
	if (format.flags & PREFIX)
		to_print -= ft_strlen(prefix);
	return (to_print);
}
	// first we need to calculate the total width needed
	// If we need to right justify, and pad with spaces, we do before the prefix
	// if the number is 0 and we have a precision of 0, we only need to pad
	// If we need to right justify, and pad with 0, we do that after the prefix
	// We print the necessary 0 padding
void	print_signed(intmax_t nb, t_format format, t_buffer *buffer)
{
	intmax_t	leftover;

	if ((nb < 0 || format.flags & SIGN || format.flags & SPACE) && format.flags & ZERO_PAD)
		--format.precision;
	format.to_print = signed_width(ft_absl(nb), format);
	// DEBUG:
	ft_putstr("To Print: ");
	ft_putnbr(format.to_print);
	ft_putstr("\n");
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width - format.to_print, buffer);
	print_signed_prefix(nb, format, buffer);
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD)
			&& !(format.flags & PRECISION))
		padd_value("0", format.width - format.to_print, buffer);
	// leftover = format.precision - get_nb_len(ft_absl(nb), 10);
	// padd_value("0", leftover, buffer);
	print_itoa_base(ft_absl(nb), 10, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width - format.to_print, buffer);
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

	format.width = unsigned_width(nb, base, prefix, format);
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width, buffer);
	print_unsigned_prefix(nb, base, prefix, format, buffer);
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD)
			&& !(format.flags & PRECISION))
		padd_value("0", format.width, buffer);
	leftover = format.precision - get_nb_len(nb, base);
	padd_value("0", leftover, buffer);
	if (!(nb == 0 && format.precision <= 0)
		|| !(base == 8 && (format.flags & PREFIX)))
		print_itoa_base(nb, base, format, buffer);
	// else if (format.width != 0)
			// buffered_print(" ", 1, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}
