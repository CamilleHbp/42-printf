/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:14:14 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/09 13:32:59 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_round(long double f)
{
	intmax_t	integer;
	long double	decimal;

	integer = (intmax_t)f;
	decimal = f - integer;
	if (f >= 0)
		return ((decimal < 0.5) ? integer : integer + 1);
	else
		return ((decimal > 0.5) ? integer : integer - 1);
}
