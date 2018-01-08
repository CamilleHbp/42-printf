/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:28 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/08 19:22:04 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "ft_printf.h"
#include "printing.h"

size_t	get_nb_len(uintmax_t nb, uint8_t base);
void	padd_value(char *char_pad, int32_t padding, t_buffer *buffer);
void	print_exponent(int64_t exponent, uint8_t base, t_format format,
						   t_buffer *buffer);
void	print_fraction(long double nb, uint8_t base, t_format format,
						  t_buffer *buffer);
void	print_itoa_base(uintmax_t nb, int8_t base, t_format format,
			char nb_str[ITOA]);

#endif
