/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:28:32 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 17:15:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"


int32_t		print_arg(t_format format, va_list *app)
{
	if (format.specifier == "di")
		print_integer(format, *app);
	else if (format.specifier == "f")
		print_float(format, *app);
	else if (format.specifier == "oubx")
		print_base(format, *app);
	else if (format.specifier == "c")
		print_char(format, *app);
	else if (format.specifier == "s")
		print_string(format, *app);
	else if (format.specifier == "p")
		print_pointer(format, *app);
	else if (format.specifier == "n")
		return_written_char(format, *app);
	return (FAILURE);
}

/*
** This implementation will aligned the buffer on x64 boundaries (8 bytes)
** It will only works on GCC and Clang.
** If we want to be portable, we will have to typedef it using declspec(align)
** for MSC support.
** 1- As long as the buffer has space, we store it in.
** 2-
*/

size_t		buffered_print(void *data, size_t size)
{
	static char	buffer[X64_SIZE] __attribute__((__aligned__(8)));
	static size_t buffer_index;
	size_t		char_written;
	int32_t		leftover;
	int64_t		i;

	leftover = X64_SIZE - buffer_index;
	while (size > leftover)
	{
		leftover = X64_SIZE - buffer_index;
		ft_memcpy(&(buffer[buffer_index]), &(data[i]), leftover);
		size -= leftover;
		i += leftover;
		buffer_index += leftover;
		char_written += leftover;
		write(1, buffer, buffer_index);
		buffer_index = 0;
	}
	ft_memcpy(&(buffer[buffer_index]), &(data[i]), leftover);
	buffer_index += size;
	char_written += leftover;
}
