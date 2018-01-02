/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:19:08 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/30 18:39:38 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(int32_t base, int32_t pow)
{
	double		ret;
	double		inverse;
	int32_t		i;

	ret = 1.0;
	i = 0;
	inverse = (double)(1.0 / base);
	while (i != pow)
	{
		ret *= (pow >= 0) ? base : inverse;
		i += (pow >= 0) ? 1 : -1;
	}
	return (ret);
}
