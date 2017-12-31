/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:54:03 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 11:54:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static long double	return_float(t_format format, va_list *app)
{
	long double	cast;

	if (format.flags & LDOUBLE)
		cast = (long double)va_arg(*app, long double);
	else
		cast = (double)va_arg(*app, double);
	return (cast);
}

size_t	print_floats(t_format format, va_list *app, t_buffer *buffer)
{
	long double number;

	number = return_float(format, app);
	if (format.specifier == 'f' || format.specifier == 'F')
		print_float_number(number, 10, format, buffer);
	/* else if (format.specifier == 'e' || format.specifier == 'E')
		print_float_scientific(number, 10, "", format, buffer);
	else if (format.specifier == 'g' || format.specifier == 'G')
		print_float_shorter(number, 10, "0", format, buffer);
	else if (format.specifier == 'a')
		print_float_scientific(number, 16, "0x", format, buffer);
	else if (format.specifier == 'A')
		print_float_scientific(number, 16, "0X", format, buffer) */;
	return (format.width);
}
