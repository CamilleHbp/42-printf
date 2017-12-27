/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:35:48 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/27 00:43:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

size_t	print_char(t_format format, va_list *app)
{
	size_t	width;
	int		printed_char;

	width = (format.width - 1 > 0) ? format.width - 1 : 1;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? '0' : ' ', width);
	if (format.flags & UNICODE)
		buffer_wchar(va_arg(*app, uint32_t));
	else
	{
		printed_char = va_arg(*app, int);
		buffered_print(&printed_char, 1);
	}
	if (format.flags & RIGHT_PAD)
		padd_value(' ', width);
	return ((format.width > 1) ? format.width : 1);
}
