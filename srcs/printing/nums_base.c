/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 22:26:27 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 22:40:58 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static uintmax_t	return_unsigned(t_format format, va_list *app)
{
	uintmax_t	cast;

	if (format.flags & SSHORT)
		cast = (unsigned char)va_arg(*app, unsigned int);
	else if (format.flags & SHORT)
		cast = (unsigned short)va_arg(*app, unsigned int);
	else if (format.flags & LONG)
		cast = (unsigned long)va_arg(*app, unsigned long);
	else if (format.flags & LLONG)
		cast = (unsigned long long)va_arg(*app, unsigned long long);
	else if (format.flags & INTMAX)
		cast = (uintmax_t)va_arg(*app, uintmax_t);
	else if (format.flags & SIZE_T)
		cast = (size_t)va_arg(*app, size_t);
	else if (format.flags & PTRDIFF)
		cast = (ptrdiff_t)va_arg(*app, ptrdiff_t);
	else
		cast = (unsigned int)va_arg(*app, unsigned int);
	return (cast);
}

size_t	print_base(t_format format, va_list *app, t_buffer *buffer)
{
	uintmax_t number;

	number = return_unsigned(format, app);
	if (format.specifier == 'u' || format.specifier == 'U')
		print_number(number, 10, "", format, buffer);
	else if (format.specifier == 'o' || format.specifier == 'O')
		print_number(number, 8, "0", format, buffer);
	else if (format.specifier == 'x')
		print_number(number, 16, "0x", format, buffer);
	else if (format.specifier == 'X')
		print_number(number, 16, "0X", format, buffer);
	else if (format.specifier == 'b')
		print_number(number, 2, "0b", format, buffer);
	else if (format.specifier == 'B')
		print_number(number, 2, "0B", format, buffer);
	return (format.width);
}
