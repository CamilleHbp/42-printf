/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:22 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 23:08:30 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	print_itoa_base(uintmax_t nb, int8_t base, t_format format,
			t_buffer *buffer)
{
	uintmax_t	tmp;
	size_t		len;
	char		*print;
	char		nb_str[ITOA];

	len = 1;
	tmp = ITOA;
	while (tmp-- > 0)
		nb_str[tmp] = 0;
	tmp = nb;
	while ((tmp /= base) > 0)
		++len;
	if (format.flags & UPPERCASE)
		print = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	print = "0123456789abcdefghijklmnopqrstuvwxyz";
	if ((nb == 0) && ((format.flags & PRECISION) && (format.precision == 0)))
		nb_str[0] = '\0';
	else if (nb == 0)
		nb_str[0] = '0';
	else
	{
		while (len--)
		{
			nb_str[len] = print[(nb % base)];
			nb /= base;
		}
	}
	buffered_print(nb_str, ft_strlen(nb_str), buffer);
 }

static void	print_prefix(intmax_t nb, uint8_t base, char *prefix,
					t_format format, t_buffer *buffer)
{
	if (base == 10)
	{
		if (nb < 0)
			buffered_print("-", 1, buffer);
		else if ((format.flags & SIGN))
			buffered_print("+", 1, buffer);
		else if ((format.flags & SPACE))
			buffered_print(" ", 1, buffer);
	}
	else if (nb != 0)
	{
		if (format.flags & PREFIX)
			buffered_print(prefix, ft_strlen(prefix), buffer);
	}
}

void	print_number(intmax_t nb, uint8_t base, char *prefix, t_format format,
			t_buffer *buffer)
{
	size_t	nb_len;
	size_t	leftover;

	// first we need to calculate the total width needed
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	nb_len = get_nb_len(nb, base);
	format.width -= (format.flags & PREFIX) ? ft_strlen(prefix) : 0;
	format.width -= ft_max(format.precision, nb_len);
	// If we need to right justify, and pad with spaces, we do before the prefix
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width, buffer);
	// if the number is 0 and we have a precision of 0, we only need to pad
	if (nb == 0 && (format.precision == 0))
		return ;
	print_prefix(nb, base, prefix, format, buffer);
	// If we need to right justify, and pad with 0, we do that after the prefix
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD))
		padd_value("0", format.width, buffer);
	// We print the necessary 0 padding
	leftover = format.precision - nb_len;
	padd_value("0", leftover, buffer);
	print_itoa_base(ft_absolute(nb), base, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}
