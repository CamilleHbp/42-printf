/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_signed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:01:45 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/09 20:28:18 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static void	print_signed_prefix(intmax_t nb, t_format format, char nb_str[ITOA])
{
	if (nb < 0)
		nb_str[0] = '-';
	else if (format.flags & SIGN)
		nb_str[0] = '+';
	else if (format.flags & SPACE)
		nb_str[0] = ' ';
}

	// If we have a 0 number and a precision of 0, we need to add 1 as we won't display the number
static int32_t signed_width(intmax_t nb, t_format format)
{
	int32_t		to_print;
	uintmax_t	tmp;

	to_print = 0;
	tmp = ft_absl(nb);
	while (tmp > 0)
	{
		tmp /= 10;
		++to_print;
	}
	to_print = ft_max(to_print, format.precision);
	if (nb < 0 || format.flags & SIGN || format.flags & SPACE)
		++to_print;
	return (to_print);
}

/*
**	first we need to calculate the total width needed
**	If we need to right justify, and pad with spaces, we do before the prefix
**	if the number is 0 and we have a precision of 0, we only need to pad
**	If we need to right justify, and pad with 0, we do that after the prefix
**	We print the necessary 0 padding
*/

void	print_signed(intmax_t nb, t_format format, t_buffer *buffer)
{
	char	nb_str[ITOA];

	if (format.flags & PRECISION)
		format.flags &= ~ZERO_PAD;
	if (format.flags & ZERO_PAD)
		format.precision = format.width;
	if ((nb < 0 || format.flags & SIGN || format.flags & SPACE)
			&& format.flags & ZERO_PAD)
		--format.precision;
	format.to_print = signed_width(nb, format);
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width - format.to_print, buffer);
	print_itoa_base(ft_absl(nb), 10, format, nb_str);
	print_signed_prefix(nb, format, nb_str);
	buffered_print(nb_str, format.to_print, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width - format.to_print, buffer);
}

static intmax_t	return_integer(t_format format, va_list *app)
{
	intmax_t	cast;

	if (format.flags & PTRDIFF)
		cast = (ptrdiff_t)va_arg(*app, ptrdiff_t);
	else if (format.flags & SIZE_T)
		cast = (size_t)va_arg(*app, size_t);
	else if (format.flags & INTMAX)
		cast = (intmax_t)va_arg(*app, intmax_t);
	else if (format.flags & LLONG)
		cast = (long long)va_arg(*app, long long);
	else if (format.flags & LONG)
		cast = (long)va_arg(*app, long);
	else if (format.flags & SHORT)
		cast = (short)va_arg(*app, int);
	else if (format.flags & SSHORT)
		cast = (char)va_arg(*app, int);
	else
		cast = (int)va_arg(*app, int);
	return (cast);
}

int32_t	print_integer(t_format format, va_list *app, t_buffer *buffer)
{
	intmax_t number;

	number = return_integer(format, app);
	print_signed(number, format, buffer);
	return (SUCCESS);
}
