/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 14:32:56 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 14:37:27 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrf(long double n, size_t size)
{
	long double decimal;

	ft_putnbr((uintmax_t)n);
	if (size > 0)
	{
		ft_putchar('.');
		decimal = n - (uintmax_t)n;
		while (size-- > 0)
			decimal *= 10;
		ft_putnbr(ft_round(decimal));
	}
}
