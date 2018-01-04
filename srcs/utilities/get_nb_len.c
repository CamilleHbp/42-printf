/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:03 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 09:46:36 by cbaillat         ###   ########.fr       */
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
