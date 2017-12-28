/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:22 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/27 22:22:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	print_itoa_base(uintmax_t nb, int8_t base, t_format format)
{
	uintmax_t	tmp;
	size_t		len;
	char		*print;
	char		nb_str[ITOA];

	tmp = nb;
	len = 1;
	while ((tmp /= base) > 0)
		++len;
	if (format.flags & UPPERCASE)
		print = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	print = "0123456789abcdefghijklmnopqrstuvwxyz";
	while (len--)
	{
		nb_str[len] = print[(nb % base)];
		nb /= base;
	}
	if ((format.flags & PRECISION) && (format.precision == 0))
		nb_str[0] = '\0';
	else
		nb_str[0] = '0';
	buffered_print(nb_str, ft_strlen(nb_str));
 }

static void	print_prefix(intmax_t nb, uint8_t base, char *prefix,
					t_format format)
{
	if (base == 10)
	{
		if (nb < 0)
			buffered_print("-", 1);
		else if ((format.flags & SIGN))
			buffered_print("+", 1);
		else if ((format.flags & SPACE))
			buffered_print(" ", 1);
	}
	else if (nb != 0)
	{
		if (format.flags & PREFIX)
			buffered_print(prefix, ft_strlen(prefix));
	}
}

void	print_number(intmax_t nb, uint8_t base, char *prefix, t_format format)
{
	size_t	nb_len;
	size_t	leftover;

	// first we need to calculate the total width needed
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	nb_len = get_nb_len(nb, base);
	format.width -= ((format.flags & ZERO_PAD) ? 0 : ft_strlen(prefix));
	format.width -= ft_max(format.precision, nb_len);

	// If we need to right justify, we pad on the left with spaces or 0
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD))
		padd_value('0', format.width);
	else if (!(format.flags & RIGHT_PAD))
		padd_value(' ', format.width);
	// if the number is 0 and we have a precision of 0, we only need to pad
	if (nb == 0 && (format.precision == 0))
		return ;
	print_prefix(nb, base, prefix, format);
	// We print the necessary 0 padding
	leftover = format.precision - nb_len;
	padd_value('0', leftover);
	print_itoa_base(ft_absolute(nb), base, format);
	if (format.flags & RIGHT_PAD)
		padd_value(' ', format.width);
}
