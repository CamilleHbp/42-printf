/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:34:20 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 22:23:35 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printing.h"

size_t	print_char(t_format format, va_list *app, t_buffer *buffer)
{
	size_t	width;
	int		printed_char;

	width = (format.width > 0) ? format.width - 1: 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	if (format.flags & UNICODE)
		buffer_wchar(va_arg(*app, wchar_t), buffer);
	else
	{
		printed_char = va_arg(*app, int);
		buffered_print(&printed_char, 1, buffer);
	}
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
	return ((format.width > 1) ? format.width : 1);
}

size_t	print_string(t_format format, va_list *app, t_buffer *buffer)
{
	char		*str;
	wchar_t		*wstr;
	intmax_t	len;
	size_t		width;

	if (format.flags & UNICODE)
		wstr = va_arg(*app, wchar_t*);
	else
		str = va_arg(*app, char*);
	len = 0;
	if (format.flags & UNICODE)
		len = (format.flags & PRECISION) ?
		ft_min(format.precision, ft_wstrlen(wstr)) : (intmax_t)ft_wstrlen(wstr);
	else
		len = (format.flags & PRECISION) ?
		ft_min(format.precision, ft_strlen(str)) : (intmax_t)ft_strlen(str);
	width = (format.width - len > 0) ? format.width - len : 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value(" ", width, buffer);
	if (format.flags & UNICODE)
		buffer_wstring(wstr, len, buffer);
	else
		buffered_print(str, len, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
	return ((format.width > len) ? format.width : len);
}
