/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:37:01 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/26 20:34:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PRINT_H
# define ARG_PRINT_H

# include "ft_printf.h"
# include "parsing.h"
# include "utils.h"

# define X64_SIZE	(size_t)64
# define NB_STR_MAX (size_t)21
# define PAD_RIGHT	(uint8_t)1
# define PAD_LEFT	(uint8_t)0
# define ITOA		(uint8_t)33

# define D_PREFIX		""
# define B_PREFIX		"0b"
# define O_PREFIX		"0"
# define X_PREFIX		"0x"
# define XUP_PREFIX		"0X"

size_t		buffered_print(void *data, size_t size);
void		buffer_wchar(uint32_t c);
void		buffer_wstring(uint32_t *str, size_t len);
void		print_itoa(intmax_t n, t_format format);

#endif
