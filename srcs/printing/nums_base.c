/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 22:26:27 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/05 14:02:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

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

size_t	print_base(t_format format, va_list *app, t_buffer *buffer)
{
	uintmax_t	number;

	number = return_arg_unsigned(format, app);
	if (format.specifier == 'u' || format.specifier == 'U')
		print_unsigned(number, 10, "", format, buffer);
	else if (format.specifier == 'o' || format.specifier == 'O')
		print_unsigned(number, 8, "0", format, buffer);
	else if (format.specifier == 'x')
		print_unsigned(number, 16, "0x", format, buffer);
	else if (format.specifier == 'X')
		print_unsigned(number, 16, "0X", format, buffer);
	else if (format.specifier == 'b')
		print_unsigned(number, 2, "0b", format, buffer);
	else if (format.specifier == 'B')
		print_unsigned(number, 2, "0B", format, buffer);
	return (format.width);
}
