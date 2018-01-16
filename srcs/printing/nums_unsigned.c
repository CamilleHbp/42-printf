/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:12:11 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 15:43:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static void			print_unsigned_prefix(t_unsigned nb, t_format format,
						t_buffer *buffer)
{
	if ((nb.nb != 0) || (format.flags & POINTER) || nb.base == 8)
		if (format.flags & PREFIX)
			buffered_print(nb.prefix, ft_strlen(nb.prefix), buffer);
}

static int32_t		unsigned_width(t_unsigned nb, t_format *format)
{
	int32_t		to_print;
	uintmax_t	tmp;

	to_print = 0;
	tmp = nb.nb;
	while (tmp > 0)
	{
		tmp /= nb.base;
		++to_print;
	}
	if (nb.base == 8 && format->flags & PREFIX)
		(to_print >= format->precision) ?
			(format->precision = to_print + 1) : 0;
	to_print = ft_max(to_print, format->precision);
	if (nb.base == 8 && format->flags & PREFIX
			&& !nb.nb && format->flags & PRECISION && format->precision <= 0)
		++to_print;
	if (nb.base != 8 && format->flags & PREFIX)
		format->width -= 2;
	return (to_print);
}

/*
** first we need to calculate the total width needed
** If we need to right justify, and pad with spaces, we do before the prefix
** If we need to right justify, and pad with 0, we do that after the prefix
** We print the necessary 0 padding
** if the number is 0 and we have a precision of 0, we only need to pad
*/

void				print_unsigned(t_unsigned nb, t_format format,
									t_buffer *buffer)
{
	char	nb_str[ITOA];

	if (format.flags & PRECISION)
		format.flags &= ~ZERO_PAD;
	format.to_print = unsigned_width(nb, &format);
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width - format.to_print, buffer);
	print_unsigned_prefix(nb, format, buffer);
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD)
			&& !(format.flags & PRECISION))
		padd_value("0", format.width - format.to_print, buffer);
	if (!(nb.nb == 0 && format.precision <= 0)
		|| !(nb.base == 8 && (format.flags & PREFIX)))
		print_itoa_base(nb, format, nb_str);
	buffered_print(nb_str, format.to_print, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width - format.to_print, buffer);
}

static uintmax_t	return_arg_unsigned(t_format format, va_list *app)
{
	uintmax_t	cast;

	if (format.flags & PTRDIFF)
		cast = va_arg(*app, ptrdiff_t);
	else if (format.flags & SIZE_T)
		cast = va_arg(*app, size_t);
	else if (format.flags & INTMAX)
		cast = va_arg(*app, uintmax_t);
	else if (format.flags & LLONG)
		cast = va_arg(*app, unsigned long long);
	else if (format.flags & LONG)
		cast = va_arg(*app, unsigned long);
	else if (format.flags & SHORT)
		cast = (unsigned short)va_arg(*app, unsigned int);
	else if (format.flags & SSHORT)
		cast = (unsigned char)va_arg(*app, unsigned int);
	else
		cast = va_arg(*app, unsigned int);
	return (cast);
}

int32_t				print_base(t_format format, va_list *app, t_buffer *buffer)
{
	t_unsigned	number;

	number.nb = return_arg_unsigned(format, app);
	number.prefix = "";
	if (format.specifier == 'u')
		number.base = 10;
	else if (format.specifier == 'o')
		number.base = 8;
	else if (format.specifier == 'x')
	{
		number.base = 16;
		number.prefix = "0x";
		if (format.flags & UPPER)
			number.prefix = "0X";
	}
	else if (format.specifier == 'b')
	{
		number.base = 2;
		number.prefix = "0b";
		if (format.flags & UPPER)
			number.prefix = "0B";
	}
	print_unsigned(number, format, buffer);
	return (SUCCESS);
}
