/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:03 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 19:16:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"



size_t	get_nb_len(uintmax_t nb, uint8_t base)
{
	size_t	nb_len;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb >= 0)
	{
		nb /= base;
		nb_len++;
	}
	return (nb_len);
}

void	padd_value(char pad_char, size_t padding)
{
	while (padding-- > 0)
		buffered_print(pad_char, 1);
}

/* void	padd_value(t_format format, int32_t flag, int32_t padding)
{
	char	padding_char;

	if (padding == 0)
		return ;
	padding_char = ' ';
	if ((flag == PAD_LEFT) && !(format.flags & RIGHT_PAD))
	{
		if (format.flags & ZERO_PAD)
			padding_char = '0';
		while (padding--)
			buffered_print(padding_char, 1);
	}
	else if ((flag == PAD_RIGHT) && (format.flags & RIGHT_PAD))
		while (padding--)
			buffered_print(padding_char, 1);
}
 */
