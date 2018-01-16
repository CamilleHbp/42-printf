/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:38:04 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 14:11:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int32_t	print_percent(t_format format, va_list *app, t_buffer *buffer)
{
	int32_t	width;

	app = (va_list*)app;
	format = (t_format)format;
	width = (format.width > 0) ? format.width - 1 : 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	buffer_wchar('%', buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
	return (SUCCESS);
}
