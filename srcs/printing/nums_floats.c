/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_floats.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:23:59 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 16:49:31 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"
#include "utils.h"

static int32_t	calculate_width(t_double nb, uint64_t dec, t_format format)
{
	if ((nb.nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	format.width -= get_nb_len(dec, nb.base);
	format.width -= ft_strlen(nb.prefix);
	format.width -= (format.precision == 0) ? 0 : format.precision + 1;
	return (format.width);
}

static void		print_sign(t_double nb, t_format format, t_buffer *buffer)
{
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width - format.to_print, buffer);
	if (nb.nb < 0)
		buffered_print("-", 1, buffer);
	buffered_print(nb.prefix, ft_strlen(nb.prefix), buffer);
}

/*
** 1- We get the dec and fraction part and calculate the decimal len for the
**	precision
** 2- If no precision is specified, it is 6
** 3- We need to calculate the total width needed
** 4- If precision is 0, we print only the rounded dec part
** 8- We print the dec part then the point, then the fraction part
*/

void			print_float_number(t_double nb, t_format format,
					t_buffer *buffer)
{
	uint64_t	dec;
	t_double	fraction;
	t_unsigned	nb_unsigned;

	if (is_denormalized(nb.nb, format, buffer) == SUCCESS)
		return ;
	dec = (uint64_t)ft_absld(nb.nb);
	fraction.nb = ft_absld(nb.nb) - dec;
	fraction.base = nb.base;
	format.width = calculate_width(nb, dec, format);
	print_sign(nb, format, buffer);
	if (format.precision == 0)
		nb_unsigned.nb = ft_absl(ft_round(nb.nb));
	else
		nb_unsigned.nb = dec;
	nb_unsigned.base = nb.base;
	buffer_itoa_base(nb_unsigned, format, buffer);
	if (format.flags & PREFIX || format.precision > 0)
		print_fraction(fraction, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}

/*
** If no precision is specified, it is 6
** If we need to right justify, and pad with spaces, we do before the prefix
** If we are in hexa, we need to print the prefix
** If we need to right justify, and pad with 0, we do that after the prefix
** If precision is 0, we print only the rounded dec part
** We print the dec part then the point, then the fraction part
** Finally we print the exponent
*/

void			print_float_scientific(t_double nb, t_format format,
					t_buffer *buffer)
{
	uint64_t	dec;
	int64_t		exponent;
	t_unsigned	nb_unsigned;
	t_double	fraction;

	fraction.base = nb.base;
	return_scient_parts(&dec, &fraction.nb, &exponent, nb);
	if (!(format.flags & PRECISION))
		format.precision = 6;
	format.width = calculate_width(nb, dec, format);
	print_sign(nb, format, buffer);
	if (format.precision == 0)
		nb_unsigned.nb = ft_round(dec + fraction.nb);
	else
		nb_unsigned.nb = dec;
	nb_unsigned.base = nb.base;
	buffer_itoa_base(nb_unsigned, format, buffer);
	if (format.flags & PREFIX || format.precision > 0)
		print_fraction(fraction, format, buffer);
	nb_unsigned.nb = ft_absl(exponent);
	nb_unsigned.base = nb.base;
	print_exponent(exponent, nb_unsigned, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}
