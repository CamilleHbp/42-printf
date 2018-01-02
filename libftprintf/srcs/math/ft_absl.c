/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 23:17:03 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 13:47:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t	ft_absl(int64_t nb)
{
   int64_t mask;

   mask = (nb >> (sizeof(int64_t) * CHAR_BIT - 1));
   nb = (uint64_t)((nb + mask) ^ mask);
   return (nb);
}
