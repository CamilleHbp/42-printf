/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:55:44 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/08 18:27:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

static char	*set_precision(char *string, t_format *format)
{
	uint32_t	digits;

	format->precision = ft_atoi(string);
	digits = format->precision;
	if (digits == 0)
		++string;
	while (digits > 0)
	{
		digits /= 10;
		++string;
	}
	if (format->precision < 0)
	{
		format->precision = 1;
		format->flags &= ~PRECISION;
	}
	return (string);
}

int32_t		seek_precision(char **string, t_format *format, va_list *app)
{
	if (**string != '.')
		return (FAILURE);
	format->flags |= PRECISION;
	*string += 1;
	if (**string == '*')
	{
		if ((format->precision = (int32_t)va_arg(*app, int)) < 0)
			format->flags &= ~PRECISION;
		*string += 1;
	}
	else if (ft_isdigit(**string))
		*string = set_precision(*string, format);
	else
		format->precision = 0;
	return (SUCCESS);
}
