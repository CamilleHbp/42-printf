/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:02:52 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/11 18:47:50 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint64_t	*x64_cpy(uint64_t *ptr, uint64_t value, size_t *len)
{
	*ptr = value;
	++ptr;
	(*len) -= 8;
	return (ptr);
}

static uint8_t	*byte_cpy(uint8_t *ptr, uint8_t value, size_t *len)
{
	*ptr = value;
	++ptr;
	(*len) -= 1;
	return (ptr);
}

void			*ft_memset(void *b, int c, size_t len)
{
	uint8_t		*byte_ptr;
	uint64_t	*x64_ptr;
	uint64_t	x64_c;

	byte_ptr = (uint8_t *)b;
	x64_c = (uint8_t)c & 0xFF;
	x64_c |= (x64_c << 56) | (x64_c << 48) | (x64_c << 40) | (x64_c << 32)
			| (x64_c << 24) | (x64_c << 16) | (x64_c << 8);
	while ((len > 0) && (((uintptr_t)(void *)(byte_ptr) & 7) != 0))
		byte_ptr = byte_cpy(byte_ptr, (uint8_t)c, &len);
	x64_ptr = (uint64_t *)byte_ptr;
	while (len >= 8)
		x64_ptr = x64_cpy(x64_ptr, x64_c, &len);
	byte_ptr = (uint8_t *)x64_ptr;
	while (len > 0)
		byte_ptr = byte_cpy(byte_ptr, (uint8_t)c, &len);
	return ((t_byte *)b);
}
