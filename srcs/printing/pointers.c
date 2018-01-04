/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 19:23:54 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 15:38:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	print_pointer(t_format *format, va_list *app, t_buffer *buffer)
{
	void	*ptr;

	ptr = va_arg(*app, void *);
	format->flags |= POINTER;
	format->flags |= PREFIX;
	print_unsigned((uintmax_t)ptr, 16, "0x", *format, buffer);
}
