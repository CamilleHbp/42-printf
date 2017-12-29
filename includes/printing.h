/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:37:01 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 22:41:19 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PRINT_H
# define ARG_PRINT_H

# include "ft_printf.h"
# include "parsing.h"
# include "utils.h"

# define NB_STR_MAX (size_t)21
# define PAD_RIGHT	(uint8_t)1
# define PAD_LEFT	(uint8_t)0
# define ITOA		(uint8_t)33

# define D_PREFIX		""
# define B_PREFIX		"0b"
# define O_PREFIX		"0"
# define X_PREFIX		"0x"
# define XUP_PREFIX		"0X"



size_t	buffered_print(void *data, size_t size, t_buffer *buffer);
void	buffer_wchar(wchar_t wchar, t_buffer *buffer);
void	buffer_wstring(wchar_t *wstr, size_t len, t_buffer *buffer);
// void		print_itoa(intmax_t n, t_format format);
int32_t	print_arg(t_format format, va_list *app, t_buffer *buffer);
size_t	print_base(t_format format, va_list *app, t_buffer *buffer);
size_t	print_char(t_format format, va_list *app, t_buffer *buffer);
size_t	print_integer(t_format format, va_list *app, t_buffer *buffer);
void	print_itoa_base(uintmax_t nb, int8_t base, t_format format,
			t_buffer *buffer);
void	print_number(intmax_t nb, uint8_t base, char *prefix, t_format format,
			t_buffer *buffer);
size_t	print_string(t_format format, va_list *app, t_buffer *buffer);

#endif
