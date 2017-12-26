/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_unicode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:07:28 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/26 20:33:06 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static void	buffer_4bytes(uint32_t wchar)
{
		uint8_t	tmp;

		tmp = ((wchar >> 18) & 0x07) | 0xF0;
		buffered_print(&tmp, 1);
		tmp = ((wchar >> 12) & 0x3F) | 0x80;
		buffered_print(&tmp, 1);
		tmp = ((wchar >> 6) & 0x3F) | 0x80;
		buffered_print(&tmp, 1);
		tmp = (wchar & 0x3F) | 0x80;
		buffered_print(&tmp, 1);
}

static void	buffer_3bytes(uint32_t wchar)
{
		uint8_t tmp;

		tmp = ((wchar >> 12) & 0x0F) | 0xE0;
		buffered_print(&tmp, 1);
		tmp = ((wchar >> 6) & 0x3F) | 0x80;
		buffered_print(&tmp, 1);
		tmp = (wchar & 0x3F) | 0x81)0;
		buffered_print(&tmp, 1);
}

static void	buffer_2bytes(uint32_t wchar)
{
		uint8_t	tmp;

		tmp = ((wchar >> 6) & 0x1F) | 0xC0;
		buffered_print(&tmp, 1);
		tmp = (wchar & 0x3F) | 0x80;
		buffered_print(&tmp, 1);
}

void		buffer_wchar(uint32_t c)
{
	if ((MB_CUR_MAX >= 2) && (c >= 0x80))
	{
		if (wchar >= 0x10000)
			buffer_4bytes(c);
		else if (wchar >= 0x800)
			buffer_3bytes(c);
		else if (wchar >= 0x80)
			buffer_2bytes(c);
	}
	else
		buffered_print(&c, 1);
}

void	buffer_wstring(uint32_t *str, size_t len)
{
	while (len)
	{
		buffer_char(*str);
		++str;
		--len;
	}
}
