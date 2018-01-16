/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:07:28 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/15 13:24:33 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static void	buffer_4bytes(wchar_t wchar, t_buffer *buffer)
{
		uint8_t	tmp[4];

		tmp[0] = ((wchar >> 18) & 0x07) | 0xF0;
		tmp[1] = ((wchar >> 12) & 0x3F) | 0x80;
		tmp[2] = ((wchar >> 6) & 0x3F) | 0x80;
		tmp[3] = (wchar & 0x3F) | 0x80;
		buffered_print(tmp, 4, buffer);
}

static void	buffer_3bytes(wchar_t wchar, t_buffer *buffer)
{
		uint8_t tmp[3];

		tmp[0] = ((wchar >> 12) & 0x0F) | 0xE0;
		tmp[1] = ((wchar >> 6) & 0x3F) | 0x80;
		tmp[2] = (wchar & 0x3F) | 0x80;
		buffered_print(tmp, 3, buffer);
}

static void	buffer_2bytes(wchar_t wchar, t_buffer *buffer)
{
		uint8_t	tmp[2];

		tmp[0] = ((wchar >> 6) & 0x1F) | 0xC0;
		tmp[1] = (wchar & 0x3F) | 0x80;
		buffered_print(tmp, 2, buffer);
}

void		buffer_wchar(wchar_t wchar, t_buffer *buffer)
{
	if (wchar >= 0x80)
	{
		if (wchar >= 0x10000)
			buffer_4bytes(wchar, buffer);
		else if (wchar >= 0x800)
			buffer_3bytes(wchar, buffer);
		else if (wchar >= 0x80)
			buffer_2bytes(wchar, buffer);
	}
	else
		buffered_print(&wchar, 1, buffer);
}

void	buffer_wstring(wchar_t *wstr, int64_t len, t_buffer *buffer)
{
	while ((len -= ft_wcharlen(*wstr)) >= 0)
		buffer_wchar(*wstr++, buffer);
}
