/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_floats_shorter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:41:21 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/14 22:59:21 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// DEBUG:
#include "stdio.h"

int32_t	compare_floats_len(long double nb, t_format format, uint8_t *precision
{
	uintmax_t	integer;
	long double	fraction;
	int64_t		exponent;
	int64_t		precision;

	return_scient_parts(&integer, &fraction, &exponent, 10, nb);
	integer = get_nb_len((uintmax_t)ft_absld(nb), 10);
		printf("precision2: %d\n", format.precision);
		printf("integer: %ld\n", integer);
		printf("exponent: %ld\n", exponent);
	if ((intmax_t)integer > format.precision || exponent <= -4)
	{
		*precision
		return (SCIENTIFIC);
	}
	if (exponent < 0)
		format.precision += ft_absl(exponent);
	precision = integer;
	fraction = nb - (intmax_t)nb;
	printf("fraction: %Lf\n", fraction);
	while (fraction < 0)
	{
		fraction *= 10;
		fraction -= (int64_t)fraction;
		++precision;
	}
	(precision < format.precision) ?
				precision : format.precision - (intmax_t)integer);
}

void	print_float_shorter(long double nb, t_format format, t_buffer *buffer)
{
	int32_t	float_leftover;

	if (!(format.flags & PRECISION))
	{
		format.flags &= PRECISION;
		format.precision = 6;
	}
	if ((float_leftover = compare_floats_len(nb, format)) == SCIENTIFIC)
	{
		format.precision = float_leftover;
		print_float_scientific(nb, 10, "", format, buffer);
	}
	else
	{
		format.precision -= float_leftover;
		printf("precision: %d", format.precision);
		print_float_number(nb, 10, format, buffer);
	}
}
