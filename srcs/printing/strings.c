/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:34:20 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/08 13:48:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printing.h"

static int32_t	print_null(int32_t precision, t_buffer *buffer)
{
	if (precision > 0)
		buffered_print("(null)", 6, buffer);
	return (SUCCESS);
}

static int32_t get_print_len(char *str, wchar_t *wstr, t_format format)
{
	intmax_t	len;
	intmax_t	strlen;

	if (format.flags & LONG)
	{
		strlen = ft_wstrlen(wstr);
		len = (format.flags & PRECISION) ?
				ft_min(format.precision, strlen) : strlen;
		len = (len < strlen) ? strlen : len;
	}
	else
	{
		strlen = ft_strlen(str);
		len = (format.flags & PRECISION) ?
				ft_min(format.precision, strlen) : strlen;
		len = (len < strlen) ? len : strlen;
	}
	return (len);
}

int32_t	print_char(t_format format, va_list *app, t_buffer *buffer)
{
	size_t	width;
	wchar_t	c;

	if (format.flags & LONG)
		c = va_arg(*app, wchar_t);
	else
		c = (wchar_t)va_arg(*app, int);
	width = (format.width > 0) ? format.width - ft_wcharlen(c): 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	if (format.flags & LONG)
		buffer_wchar(c, buffer);
	else
		buffered_print(&c, 1, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
	return (SUCCESS);
}

int32_t	print_string(t_format format, va_list *app, t_buffer *buffer)
{
	char		*str;
	wchar_t		*wstr;
	intmax_t	len;
	size_t		width;

	str = "";
	wstr = L"";
	if (format.flags & LONG)
	{
		if ((wstr = va_arg(*app, wchar_t*)) == NULL)
			return (print_null(format.precision, buffer));
	}
	else
		if ((str = va_arg(*app, char*)) == NULL)
			return (print_null(format.precision, buffer));
	len = get_print_len(str, wstr, format);
	width = (format.width - len > 0) ? format.width - len : 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	if (format.flags & LONG)
		buffer_wstring(wstr, len, buffer);
	else
		buffered_print(str, len, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
	return (SUCCESS);
}
