/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:28 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 19:16:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "ft_printf.h"

# define PAD_MINUS	(uint8_t)1
# define PAD		(uint8_t)0
# define ITOA		(uint8_t)33


uintmax_t	absolute(intmax_t n);
void		print_itoa(intmax_t n, t_format format);
int32_t		max(int32_t n);

#endif
