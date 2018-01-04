/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 14:38:04 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 14:41:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	print_percent(t_format format, t_buffer *buffer)
{
	size_t	width;

	width = (format.width > 0) ? format.width - 1: 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	buffer_wchar('%', buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
}
