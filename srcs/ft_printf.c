/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:46:29 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 13:48:22 by cbaillat         ###   ########.fr       */
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
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*tmp;
	t_buffer	buffer;

	tmp = (char *)format;
	init_buffer(&buffer);
	va_start(ap, format);
	while (*tmp != '\0')
	{
		if (*tmp == '%')
			tmp = parse_format(tmp + 1, &ap, &buffer);
		else
		{
			buffered_print(tmp, 1, &buffer);
			++tmp;
		}
	}
	write(1, buffer.buffer, buffer.buffer_index);
	va_end(ap);
	return (SUCCESS);
}
