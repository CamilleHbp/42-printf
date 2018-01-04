/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 09:45:56 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 09:46:06 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	padd_value(char *pad_char, int32_t padding, t_buffer *buffer)
{
	while (padding-- > 0)
		buffered_print(pad_char, 1, buffer);
}
