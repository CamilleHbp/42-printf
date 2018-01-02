/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:24:48 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 19:06:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_INT_LENGTH 11

void	ft_putnbr(int n)
{
	char	number[MAX_INT_LENGTH];
	int		digit;

	digit = 0;
	if (n > 0)
		n *= -1;
	else if (n == 0)
		ft_putchar('0');
	else
		ft_putchar('-');
	while (n < 0)
	{
		number[digit] = -(n % 10) + '0';
		n = n / 10;
		digit++;
	}
	digit--;
	while (digit >= 0)
	{
		ft_putchar(number[digit]);
		digit--;
	}
}
