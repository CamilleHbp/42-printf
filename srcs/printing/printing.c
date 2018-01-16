/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:28:32 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 12:47:10 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static t_functions	g_functions[] =
{
	{print_percent, '%'},
	{print_integer, 'd'},
	{print_integer, 'i'},
	{print_base, 'x'},
	{print_base, 'o'},
	{print_base, 'u'},
	{print_bytes, 'n'},
	{print_string, 's'},
	{print_char, 'c'},
	{print_pointer, 'p'},
	{print_floats, 'f'},
	{print_floats, 'e'},
	{print_floats, 'a'},
	{print_floats, 'g'},
	{print_base, 'b'},
	{NULL, FAILURE}
};

static int	print_function(t_format format, va_list *app,
				t_buffer *buffer)
{
	int32_t	i;

	i = 0;
	while (g_functions[i].specifier != FAILURE)
	{
		if (g_functions[i].specifier == format.specifier)
			return (g_functions[i].ptrfunc(format, app, buffer));
		i++;
	}
	return (FAILURE);
}

static int32_t	undefined_behaviour(t_format format, t_buffer *buffer)
{
	int32_t	width;
	char	undefined_char[2];

	if (!format.specifier)
		return (FAILURE);
	width = (format.width > 0) ? format.width - 1: 0;
	if (!(format.flags & RIGHT_PAD))
		padd_value((format.flags & ZERO_PAD) ? "0" : " ", width, buffer);
	undefined_char[1] = '\0';
	undefined_char[0] = format.specifier;
	buffered_print(undefined_char, ft_strlen(undefined_char), buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", width, buffer);
	// buffer->undefined_behaviour = UNDEFINED_BEHAVIOUR;
	return (FAILURE);
}

int32_t	print_arg(t_format format, va_list *app, t_buffer *buffer)
{
	if (print_function(format, app, buffer) == FAILURE)
		return (undefined_behaviour(format, buffer));
	return (SUCCESS);
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

void	buffered_print(void *void_data, size_t size, t_buffer *buf)
{
	uint32_t	leftover;
	uint8_t		*data;
	int64_t		i;

	data = (uint8_t *)void_data;
	i = 0;
	while (size > (X64_SIZE - buf->buffer_index))
	{
		leftover = X64_SIZE - buf->buffer_index;
		ft_memcpy(&(buf->buffer[buf->buffer_index]), &(data[i]), leftover);
		size -= leftover;
		i += leftover;
		buf->buffer_index += leftover;
		buf->bytes_written += leftover;
		write(1, buf->buffer, buf->buffer_index);
		buf->buffer_index = 0;
	}
	ft_memcpy(&(buf->buffer[buf->buffer_index]), &(data[i]), size);
	buf->buffer_index += size;
	buf->bytes_written += size;
}
