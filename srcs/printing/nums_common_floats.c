/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common_floats.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:23:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/09 13:41:43 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

/*
** 1- Divide or multiply the number until we have only one digit left
** 2- We get the integer and fraction part and calculate the decimal len for the
**	precision
*/

static void	return_scient_parts(uint64_t *integer, long double *fraction,
								int64_t *exponent, uint8_t base, long double nb)
{
	*integer = 0;
	*fraction = 0.0;
	*exponent = 0;
	if (nb == 0)
		return ;
	else if (nb >= 1)
		while (nb > ((base == 10) ? base - 1 : 2))
		{
			nb /= (base == 10) ? base : 2;
			*exponent += 1;
		}
	else if (nb < 1)
		while (nb < 1)
		{
			nb *= (base == 10) ? base : 2;
			*exponent -= 1;
		}
	*integer = (uint64_t)nb;
	*fraction = nb - *integer;
}

/*
** 1- First we need to calculate the total width needed
** 2- If the format precision is not 0, we need to subtract 1 more for the '.'
*/

/* static int32_t calculate_width(long double nb, uint64_t integer, uint8_t base,
					char *prefix, t_format format)
{
	int32_t	to_print;

	to_print = 0;
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		++format.to_print;
	to_print += get_nb_len(integer, base);
	to_print += ft_strlen(prefix);
	to_print += (format.precision == 0) ? 0 : format.precision + 1;
	return (to_print);
}*/

static int32_t calculate_width(long double nb, uint64_t integer, uint8_t base,
					char *prefix, t_format format)
{
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	format.width -= get_nb_len(integer, base);
	format.width -= ft_strlen(prefix);
	format.width -= (format.precision == 0) ? 0 : format.precision + 1;
	return (format.width);
}

static void		print_sign(long double nb, char *prefix, t_format format,
					t_buffer *buffer)
{
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width - format.to_print, buffer);
	if (nb < 0)
		buffered_print("-", 1, buffer);
	buffered_print(prefix, ft_strlen(prefix), buffer);
}

/*
** 1- We get the integer and fraction part and calculate the decimal len for the
**	precision
** 2- If no precision is specified, it is 6
** 3- We need to calculate the total width needed
** 4- If precision is 0, we print only the rounded integer part
** 8- We print the integer part then the point, then the fraction part
*/

void	print_float_number(long double nb, uint8_t base, t_format format,
						t_buffer *buffer)
{
	uint64_t	integer;
	long double	fraction;

	integer = ft_absld(nb);
	fraction = ft_absld(nb) - integer;
	if (!(format.flags & PRECISION))
		format.precision = 6;
	format.width = calculate_width(nb, integer, base, "", format);
	print_sign(nb, "", format, buffer);
	if (format.precision == 0)
		buffer_itoa_base(ft_absl(ft_round(nb)), base, format, buffer);
	else
		buffer_itoa_base(integer, base, format, buffer);
	if (format.flags & PREFIX || format.precision > 0)
	{
		buffered_print(".", 1, buffer);
		print_fraction(fraction, base, format, buffer);
	}
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}

/*
** If no precision is specified, it is 6
** If we need to right justify, and pad with spaces, we do before the prefix
** If we are in hexa, we need to print the prefix
** If we need to right justify, and pad with 0, we do that after the prefix
** If precision is 0, we print only the rounded integer part
** We print the integer part then the point, then the fraction part
*/

void	print_float_scientific(long double nb, uint8_t base, char *prefix,
							t_format format, t_buffer *buffer)
{
	uint64_t	integer;


	int64_t		exponent;
	long double fraction;

	return_scient_parts(&integer, &fraction, &exponent, base, ft_absld(nb));
	if (!(format.flags & PRECISION))
		format.precision = 6;
	format.width = calculate_width(nb, integer, base, prefix, format);
	print_sign(nb, prefix, format, buffer);
	if (format.precision == 0)
		buffer_itoa_base(ft_round(integer + fraction), base, format, buffer);
	else
		buffer_itoa_base(integer, base, format, buffer);
	if (format.flags & PREFIX || format.precision > 0)
	{
		buffered_print(".", 1, buffer);
		print_fraction(fraction, base, format, buffer);
	}
	print_exponent(exponent, base, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}
