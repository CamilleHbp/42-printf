/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:28 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 13:51:58 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "ft_printf.h"
#include "printing.h"

size_t		get_nb_len(uintmax_t nb, uint8_t base);
void		padd_value(char *char_pad, int32_t padding, t_buffer *buffer);

#endif
