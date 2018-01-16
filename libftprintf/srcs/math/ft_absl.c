/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 23:17:03 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 14:43:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_absl(intmax_t nb)
{
	intmax_t mask;

	mask = (nb >> (sizeof(nb) * CHAR_BIT - 1));
	nb = (uintmax_t)((nb + mask) ^ mask);
	return (nb);
}
