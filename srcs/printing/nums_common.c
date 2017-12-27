/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:22 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/27 10:39:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	itoa_base(uintmax_t nb, int8_t base, char s[ITOA], t_format format)
{
	uintmax_t	tmp;
	size_t		len;
	char		*print;

	tmp = nb;
	len = 1;
	while ((tmp /= base) > 0)
		++len;
	if (format.flags & UPPERCASE)
		print = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	print = "0123456789abcdefghijklmnopqrstuvwxyz";
	while (len--)
	{
		s[len] = print[(nb % base)];
		n /= base;
	}
	if ((format.flags & PRECISION) && (format.precision == 0))
		s[0] = '\0';
	else
		s[0] = '0';
 }

static void	print_prefix(intmax_t nb, uint8_t base, char *prefix, t_format *format)
{
	if (base == 10)
	{
		if (nb < 0)
			buffered_print("-", 1);
		else if ((format.flags & SIGN))
			buffered_print("+", 1);
		else if ((format.flags & BLANK))
			buffered_print(" ", 1);
	}
	else if (nb != 0)
	{
		if (format.flags & PREFIX)
			buffered_print(prefix, ft_strlen(prefix));
	}
}

void	print_number(intmax_t nb, uint8_t base, char *prefix, t_format *format)
{
	char	*nb_str[NB_STR_MAX];
	size_t	nb_len;
	size_t	leftover;

	// first we need to calculate the total width needed
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & BLANK))
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
	if (nb == 0 && (format->precision == 0))
		return ;
	print_prefix(nb, base, prefix, format);
	// We print the necessary 0 padding
	leftover = format->precision - nb_len;
	while (leftover > 0)
		padd_value('0', nb_display_len);
	atoi_base(ft_absolute(nb), base);
	if (format.flags & RIGHT_PAD)
		padd_value(' ', format.width);
}
