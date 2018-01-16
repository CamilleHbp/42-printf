/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:34:20 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 14:31:09 by cbaillat         ###   ########.fr       */
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

static int32_t	get_print_len(char *str, wchar_t *wstr, t_format format)
{
	intmax_t	len;
	intmax_t	strlen;

	strlen = 0;
	len = 0;
	if (format.flags & LONG)
	{
		len = format.precision;
		while (*wstr != L'\0')
		{
			if (format.flags & PRECISION && ft_wcharlen(*wstr) > (size_t)len)
				break ;
			strlen += ft_wcharlen(*wstr);
			len -= ft_wcharlen(*wstr);
			++wstr;
		}
		len = strlen;
	}
	else
	{
		strlen = ft_strlen(str);
		len = (format.flags & PRECISION) ?
				ft_min(format.precision, strlen) : strlen;
	}
	return (len);
}

int32_t			print_char(t_format format, va_list *app, t_buffer *buffer)
{
	size_t	width;
	wchar_t	c;

	if (format.flags & LONG)
		c = va_arg(*app, wchar_t);
	else
		c = (wchar_t)va_arg(*app, int);
	width = (format.width > 0) ? format.width - ft_wcharlen(c) : 0;
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

int32_t			print_string(t_format format, va_list *app, t_buffer *buffer)
{
	char		*str;
	wchar_t		*wstr;

	str = "";
	wstr = L"";
	if (format.flags & LONG)
		wstr = va_arg(*app, wchar_t*);
	else
		str = va_arg(*app, char*);
	if (wstr != NULL && str != NULL)
		format.precision = get_print_len(str, wstr, format);
	else if (format.precision > 0)
		return (print_null(format.precision, buffer));
	format.width = (format.width - format.precision > 0) ?
						format.width - format.precision : 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", format.width, buffer);
	if (format.flags & LONG && wstr != NULL)
		buffer_wstring(wstr, format.precision, buffer);
	else if (str != NULL)
		buffered_print(str, format.precision, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
	return (SUCCESS);
}
