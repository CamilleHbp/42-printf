/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:32:21 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 19:05:00 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MAX_INT		(int)2147483647
#define MIN_INT		(int)-2147483648
#define OVERFLOW	(int)-1
#define UNDERFLOW	(int)0
#define SUCCESS		(int)-1

static int	ft_getsignedness(char c, int *sign)
{
	if ((c == '+') || (c == '-'))
	{
		if (c == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

static int	ft_checkoverflow(int number, int digit, int sign)
{
	if (number > (MAX_INT / 10))
	{
		if (sign == 1)
			return (OVERFLOW);
		else
			return (UNDERFLOW);
	}
	else if (number == (MAX_INT / 10))
	{
		if (sign == 1 && (digit > 7))
			return (OVERFLOW);
		if (sign == -1 && (digit < 8))
			return (OVERFLOW);
	}
	return (SUCCESS);
}

int			ft_atoi(const char *str)
{
	int		sign;
	int		number;
	int		digit;
	int		no_overflow;

	sign = 1;
	number = 0;
	no_overflow = OVERFLOW;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		++str;
	if (ft_getsignedness(*str, &sign))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		digit = *str - '0';
		if ((no_overflow = ft_checkoverflow(number, digit, sign)) != SUCCESS)
			return (no_overflow);
		number = (number * 10) + digit;
		++str;
	}
	if (number > MAX_INT)
		return (OVERFLOW);
	return (number * sign);
}
