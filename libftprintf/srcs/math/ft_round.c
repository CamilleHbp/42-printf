/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 18:14:14 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/31 14:42:09 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_round(long double f)
{
	uintmax_t	integer;
	long double	decimal;

	integer = (uintmax_t)f;
	decimal = f - integer;
	return ((decimal < 0.5) ? integer : integer + 1);
}
