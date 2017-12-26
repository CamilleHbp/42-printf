/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:35:48 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/26 20:24:53 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

size_t	print_char(t_format format, va_list *app)
{
	size_t	width;

	width = (format.width - 1 > 0) ? format.width - 1 : 1;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? '0' : ' ', width);
	if (format.flags & UNICODE)
		buffer_wchar(va_arg(*app, uint32_t));
	else
		buffered_print(va_arg(*app, char), 1);
	if (format.flags & RIGHT_PAD)
		padd_value(' ', width);
	return ((format.width > 1) ? format.width : 1);
}
