/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_written.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 11:51:35 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/08 12:25:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

int32_t	print_bytes(t_format format, va_list *app, t_buffer *buffer)
{
	format = (t_format)format;
	*va_arg(*app, int *) = buffer->bytes_written;
	return (SUCCESS);
}
