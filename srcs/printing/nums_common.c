/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:22 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/20 23:33:22 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static int32_t		print_integer(t_format format, va_list *app)
{
	intmax_t	cast;

	if (fomat.len == hh)
		cast = (char)va_arg(*app, int);
	else if (fomat.len == h)
		cast = (short)va_arg(*app, int);
	else if (fomat.len == l)
		cast = (long)va_arg(*app, int);
	else if (fomat.len == ll)
		cast = (long long)va_arg(*app, int);
	else if (fomat.len == j)
		cast = (intmax_t)va_arg(*app, int);
	else if (fomat.len == z)
		cast = (size_t)va_arg(*app, int);
	else if (fomat.len == t)
		cast = (ptrdiff_t)va_arg(*app, int);
	else
		cast = (int)va_arg(*app, int);
	itoa(cast, format)
}
