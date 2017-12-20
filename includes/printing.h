/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:37:01 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/20 23:37:01 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_PRINT_H
# define ARG_PRINT_H

#include "ft_printf.h"
#include "parsing.h"
#include "utils.h"

#define X64_SIZE (size_t)64

size_t		buffered_print(void *data, size_t size);
void		print_itoa(intmax_t n, t_format format);

#endif
