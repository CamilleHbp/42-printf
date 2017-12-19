/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 09:24:36 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 19:16:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_print.h"

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
