/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_floats_shorter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:41:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 16:33:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int32_t	compare_floats_len(t_double nb, t_format format, int64_t *precision)
{
	uint64_t	integer;
	long double	fraction;
	int64_t		exponent;

	return_scient_parts(&integer, &fraction, &exponent, nb);
	integer = get_nb_len((uintmax_t)ft_absld(nb.nb), 10);
	if ((intmax_t)integer > format.precision || exponent <= -4)
	{
		*precision = format.precision - (intmax_t)integer;
		return (SCIENTIFIC);
	}
	if (exponent < 0)
		format.precision += ft_absl(exponent);
	*precision = integer;
	fraction = nb.nb - (intmax_t)nb.nb;
	while (fraction < 0)
	{
		fraction *= 10;
		fraction -= (int64_t)fraction;
		++precision;
	}
	*precision = (*precision < format.precision) ?
				*precision : format.precision - (intmax_t)integer;
	return (FLOAT);
}

void	print_float_shorter(t_double nb, t_format format, t_buffer *buffer)
{
	int64_t	precision;

	if (compare_floats_len(nb, format, &precision) == SCIENTIFIC)
	{
		format.precision = precision;
		print_float_scientific(nb, format, buffer);
	}
	else
	{
		format.precision = precision;
		print_float_number(nb, format, buffer);
	}
}
