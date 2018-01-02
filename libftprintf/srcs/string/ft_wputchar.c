/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:11:33 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 21:55:20 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We test the utf-8 char to see how many bytes it has.
** Depending on that, we use mask to write value without the
*/

static void	print_4bytes(wchar_t wchar)
{
		uint8_t	tmp;

		tmp = ((wchar >> 18) & 0x07) | 0xF0;
		write(1, &tmp, 1);
		tmp = ((wchar >> 12) & 0x3F) | 0x80;
		write(1, &tmp, 1);
		tmp = ((wchar >> 6) & 0x3F) | 0x80;
		write(1, &tmp, 1);
		tmp = (wchar & 0x3F) | 0x80;
		write(1, &tmp, 1);
}

static void	print_3bytes(wchar_t wchar)
{
		uint8_t tmp;

		tmp = ((wchar >> 12) & 0x0F) | 0xE0;
		write(1, &tmp, 1);
		tmp = ((wchar >> 6) & 0x3F) | 0x80;
		write(1, &tmp, 1);
		tmp = (wchar & 0x3F) | 0x80;
		write(1, &tmp, 1);
}

static void	print_2bytes(wchar_t wchar)
{
		uint8_t	tmp;

		tmp = ((wchar >> 6) & 0x1F) | 0xC0;
		write(1, &tmp, 1);
		tmp = (wchar & 0x3F) | 0x80;
		write(1, &tmp, 1);
}

static void	print_utf8(wchar_t wchar)
{
		if (wchar >= 0x10000)
				print_4bytes(wchar);
		else if (wchar >= 0x800)
				print_3bytes(wchar);
		else if (wchar >= 0x80)
				print_2bytes(wchar);
}


void		ft_wputchar(wchar_t wc)
{
		if ((MB_CUR_MAX >= 2) && (wc >= 0x80))
				print_utf8(wc);
		else
				write(1, &wc, 1);
}
