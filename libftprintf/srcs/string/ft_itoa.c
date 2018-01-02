/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:40:13 by cbaillat          #+#    #+#             */
/*   Updated: 2017/11/23 19:06:02 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_return_len(int number, int *sign)
{
	size_t	len;

	len = 0;
	if (number < 0)
	{
		++len;
		*sign = -1;
	}
	else
		number = -number;
	while (number < 0)
	{
		number /= 10;
		++len;
	}
	return (len);
}

static char		*ft_print_zero(void)
{
	char	*s_zero;

	if ((s_zero = (char *)malloc(sizeof(*s_zero) * 2)) == NULL)
		return (NULL);
	s_zero[0] = '0';
	s_zero[1] = '\0';
	return (s_zero);
}

char			*ft_itoa(int n)
{
	int		sign;
	long	cast_n;
	size_t	len;
	char	*str;

	if (n == 0)
		return (ft_print_zero());
	sign = 1;
	len = ft_return_len(n, &sign);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	else
		n = -n;
	str[len] = '\0';
	--len;
	cast_n = n;
	while (cast_n < 0)
	{
		str[len] = (-cast_n % 10) + '0';
		cast_n /= 10;
		--len;
	}
	return (str);
}
