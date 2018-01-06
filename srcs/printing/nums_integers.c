/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_integers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:14 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/05 14:02:10 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static intmax_t	return_integer(t_format format, va_list *app)
{
	intmax_t	cast;

	if (format.flags & PTRDIFF)
		cast = (ptrdiff_t)va_arg(*app, ptrdiff_t);
	else if (format.flags & SIZE_T)
		cast = (size_t)va_arg(*app, size_t);
	else if (format.flags & INTMAX)
		cast = (intmax_t)va_arg(*app, intmax_t);
	else if (format.flags & LLONG)
		cast = (long long)va_arg(*app, long long);
	else if (format.flags & LONG)
		cast = (long)va_arg(*app, long);
	else if (format.flags & SHORT)
		cast = (short)va_arg(*app, int);
	else if (format.flags & SSHORT)
		cast = (char)va_arg(*app, int);
	else
		cast = (int)va_arg(*app, int);
	return (cast);
}

size_t	print_integer(t_format format, va_list *app, t_buffer *buffer)
{
	intmax_t number;

	number = return_integer(format, app);
	print_signed(number, 10, "", format, buffer);
	return (format.width);
}
