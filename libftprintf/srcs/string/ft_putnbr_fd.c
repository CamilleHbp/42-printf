/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:07:04 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 19:06:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_INT_LENGTH 11

void	ft_putnbr_fd(int n, int fd)
{
	char	number[MAX_INT_LENGTH];
	int		digit;

	digit = 0;
	if (n > 0)
		n *= -1;
	else if (n == 0)
		ft_putchar_fd('0', fd);
	else
		ft_putchar_fd('-', fd);
	while (n < 0)
	{
		number[digit] = -(n % 10) + '0';
		n = n / 10;
		digit++;
	}
	digit--;
	while (digit >= 0)
	{
		ft_putchar_fd(number[digit], fd);
		digit--;
	}
}
