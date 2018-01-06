/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:46:29 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/05 13:36:22 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parsing.h"
#include "printing.h"

static void	init_buffer(t_buffer *buffer)
{
	int32_t	i;

	i = X64_SIZE;
	buffer->buffer_index = 0;
	while (i-- >= 0)
		buffer->buffer[i] = 0;
	buffer->bytes_written = 0;
	buffer->undefined_behaviour = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*str;
	t_buffer	buffer;

	str = (char *)format;
	init_buffer(&buffer);
	va_start(ap, format);
	while (*str != '\0')
	{
		if (*str == '%')
			str = parse_format(str + 1, &ap, &buffer);
		else
			buffered_print(str++, 1, &buffer);
	}
	write(1, buffer.buffer, buffer.buffer_index);
	va_end(ap);
	if (buffer.undefined_behaviour == UNDEFINED_BEHAVIOUR)
		return (UNDEFINED_BEHAVIOUR);
	return (buffer.bytes_written);
}
