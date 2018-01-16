/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_floats_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:54:03 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 15:17:51 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static long double	return_float(t_format format, va_list *app)
{
	long double cast;

	if (format.flags & LDOUBLE)
		cast = (long double)va_arg(*app, long double);
	else
		cast = (double)va_arg(*app, double);
	return (cast);
}

int32_t				print_floats(t_format format, va_list *app,
						t_buffer *buffer)
{
	t_double number;

	number.nb = return_float(format, app);
	if (!(format.flags & PRECISION))
		format.precision = 6;
	if (ft_strchr("fge", format.specifier) != NULL)
	{
		number.base = 10;
		number.prefix = "";
		if (format.specifier == 'f')
			print_float_number(number, format, buffer);
		else if (format.specifier == 'e')
			print_float_scientific(number, format, buffer);
		else if (format.specifier == 'g')
			print_float_shorter(number, format, buffer);
	}
	else if (format.specifier == 'a')
	{
		number.base = 16;
		number.prefix = "0x";
		if (format.specifier == 'a' && format.flags & UPPER)
			number.prefix = "0X";
		print_float_scientific(number, format, buffer);
	}
	return (SUCCESS);
}
