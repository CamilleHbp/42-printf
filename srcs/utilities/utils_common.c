/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_common.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:03 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 13:52:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	get_nb_len(uintmax_t nb, uint8_t base)
{
	size_t	nb_len;

	if (nb == 0)
		return (1);
	nb_len = 0;
	while (nb > 0)
	{
		nb /= base;
		nb_len++;
	}
	return (nb_len);
}

void	padd_value(char *pad_char, int32_t padding, t_buffer *buffer)
{
	while (padding-- > 0)
		buffered_print(pad_char, 1, buffer);
}
