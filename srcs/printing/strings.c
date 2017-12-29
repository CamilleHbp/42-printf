/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:34:20 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 21:47:16 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printing.h"

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
	{
		while (wstr[len] != L'\0')
			++len;
	ft_putstr("wlen: ");
	ft_putnbr(len);
	ft_putchar('\n');
		len = (format.flags & PRECISION) ? ft_min(format.precision, len) : len;
	}
	else
		len = (format.flags & PRECISION) ? ft_min(format.precision, ft_strlen(str)) : (intmax_t)ft_strlen(str);
	ft_putstr("len: ");
	ft_putnbr(len);
	ft_putchar('\n');
	ft_putstr("precision: ");
	ft_putnbr(format.precision);
	ft_putchar('\n');
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
