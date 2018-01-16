/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floats_scient.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:25:39 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 16:24:10 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_exponent(int64_t exponent, t_unsigned print_exp, t_format format,
						t_buffer *buffer)
{
	if (print_exp.base == 16)
	{
		if (format.flags & UPPER)
			buffered_print("P", 1, buffer);
		else
			buffered_print("p", 1, buffer);
	}
	else
	{
		if (format.flags & UPPER)
			buffered_print("E", 1, buffer);
		else
			buffered_print("e", 1, buffer);
	}
	if (exponent >= 0)
		buffered_print("+", 1, buffer);
	else
		buffered_print("-", 1, buffer);
	if (((exponent < 9) && (exponent > -9)) && (print_exp.base == 10))
		buffered_print("0", 1, buffer);
	if (exponent == 0)
		buffered_print("0", 1, buffer);
	else
		buffer_itoa_base(print_exp, format, buffer);
}

/*
** 1- Divide or multiply the number until we have only one digit left
** 2- We get the integer and fraction part and calculate the decimal len for the
**	precision
*/

void	return_scient_parts(uint64_t *integer, long double *fraction,
					int64_t *exponent, t_double nb)
{
	*integer = 0;
	*fraction = 0.0;
	*exponent = 0;
	if (nb.nb == 0)
		return ;
	else if (nb.nb >= 1)
		while (nb.nb > ((nb.base == 10) ? nb.base - 1 : 2))
		{
			nb.nb /= (nb.base == 10) ? nb.base : 2;
			*exponent += 1;
		}
	else if (nb.nb < 1)
		while (nb.nb < 1)
		{
			nb.nb *= (nb.base == 10) ? nb.base : 2;
			*exponent -= 1;
		}
	*integer = (uint64_t)nb.nb;
	*fraction = nb.nb - *integer;
}
