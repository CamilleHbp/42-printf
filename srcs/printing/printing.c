/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:28:32 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 20:25:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"


int32_t		print_arg(t_format format, va_list *app, t_buffer *buffer)
{
	if ((format.specifier == 'd') || (format.specifier == 'i')
		|| (format.specifier == 'D') || (format.specifier == 'i'))
		print_integer(format, app, buffer);
	// else if (format.specifier == "f")
		// print_float(format, app);
	// else if (format.specifier == "oubx")
		// print_base(format, app);
	else if ((format.specifier == 'c') || (format.specifier == 'C'))
		print_char(format, app, buffer);
	else if ((format.specifier == 's') || (format.specifier == 'S'))
		print_string(format, app, buffer);
	// else if (format.specifier == "p")
		// print_pointer(format, app);
	// else if (format.specifier == "n")
		// return_written_char(format, app);
	return (FAILURE);
}

/*
** This implementation will align the buffer on x64 boundaries (8 bytes)
** It will only work on GCC and Clang.
** If we want to be portable, we will have to typedef it using declspec(align)
** for MSC support.
** 1- First we check if we have enough space in the buffer
** 2- If not, we copy the data we can in the buffer using memcpy with leftover
** 3- We then write all the buffer, and check if
** 2- As long as the buffer has space, we store it in.
*/

size_t		buffered_print(void *void_data, size_t size, t_buffer *buf)
{
	size_t			char_written;
	uint32_t		leftover;
	uint8_t			*data;
	int64_t			i;

	data = (uint8_t*)void_data;
	i = 0;
	char_written = 0;
	while (size > (X64_SIZE - buf->buffer_index))
	{
		leftover = X64_SIZE - buf->buffer_index;
		ft_memcpy(&(buf->buffer[buf->buffer_index]), &(data[i]), leftover);
		size -= leftover;
		i += leftover;
		buf->buffer_index += leftover;
		char_written += leftover;
		write(1, buf->buffer, buf->buffer_index);
		buf->buffer_index = 0;
	}
	ft_memcpy(&(buf->buffer[buf->buffer_index]), &(data[i]), size);
	buf->buffer_index += size;
	char_written += size;
	return (char_written);
}
