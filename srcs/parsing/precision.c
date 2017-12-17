/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:55:44 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 20:53:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

/*
** PRECISION:
** .number	dDioOuUxX:
**		precision specifies the minimum number of digits to be written.
**		If the value is shorter, the result is padded with leading zeros.
**		The value is not truncated even if the result is longer.
**		A precision of 0 means that no character is written for the value 0.
**			aAeEfFgG:
**		number of digits to be printed after the decimal point (default is 6).
**			s:
**		this is the maximum number of characters to be printed.
**		If the period is specified without an explicit value for precision,
**		0 is assumed.
** .*	The precision is not specified in the format string, but as an
**		additional integer value argument preceding the argument that has to be
**		formatted.
*/

/*
** If the char is a . we check the next one
** If the char is a *, we need to turn on the flag, and later get the next
** argument to get the real width.
** If we find a number, ft_atoi will get us the number up to the next non-digit
** char, and we will need to offset the string pointer, to avoid parsing them
** again.
** If we find nothing,  0 is assumed.
*/

int32_t	seek_precision(char **string, t_format *format, va_list *app)
{
	uint32_t	digits;

	if (**string != '.')
		return (FAILURE);
	*string += 1;
	if (**string == '*')
	{
		format->precision = (int32_t)va_arg(*app, int);
		*string += 1;
		return (SUCCESS);
	}
	else if (ft_isdigit(**string))
	{
		format->precision = ft_atoi(*string);
		digits = format->precision;
		while (digits > 0)
		{
			*string += 1;
			digits /= 10;
		}
		return (SUCCESS);
	}
	else
	{
		format->precision = 0;
		return (SUCCESS);
	}
}
