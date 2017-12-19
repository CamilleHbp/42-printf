/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:58:03 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 19:16:45 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

uintmax_t	absolute(intmax_t n)
{
	if (n < 0)
		return ((uintmax_t)-n);
	return ((uintmax_t)n);
}

int32_t		max(int32_t a, int32_t b)
{
	if (b > a)
		return (b);
	return (a);
}

void	padd_value(t_format format, int32_t flag, int32_t padding)
{
	char	padding_char;

	if (!padding)
		return ;
	padding_char = ' ';
	if (search(format.flag, zero) == SUCCESS)
		padding_char = '0';
	if ((flag == PAD) && (search_flag(format.flag, minus) == FAILURE))
		while (padding--)
	buffered_print(padding_char, 1);
	else if ((flag == PAD_MINUS) && (search_flag(format.flag, minus) == SUCCESS))
		while (padding--)
			buffered_print(padding_char, 1);
}
