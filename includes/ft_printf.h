/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:47:02 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/03 20:25:10 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>

# include "libft.h"

# define SUCCESS				(int32_t)0
# define FAILURE				(int32_t)-1
# define UNDEFINED_BEHAVIOUR	(int8_t)-1
# define MALLOC_FAIL			(int32_t)-2

# define X64_SIZE	(size_t)64

typedef struct	s_format
{
	uint32_t	flags;
	int32_t		width;
	int32_t		precision;
	char		specifier;
}				t_format;

typedef struct	s_buffer
{
	char		buffer[X64_SIZE] __attribute__((__aligned__(8)));
	size_t		buffer_index;
	uintmax_t	bytes_written;
	int8_t		undefined_behaviour;
}				t_buffer;

int	ft_printf(const char *format, ...);

#endif
