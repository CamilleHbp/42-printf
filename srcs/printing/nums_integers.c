/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_integers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:14 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/27 10:19:16 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static intmax_t	return_integer(t_format format, va_list *app)
{
	intmax_t	cast;

	if (format.flags & SSHORT)
		cast = (char)va_arg(*app, int);
	else if (format.flags & SHORT)
		cast = (short)va_arg(*app, int);
	else if (format.flags & LONG)
		cast = (long)va_arg(*app, int);
	else if (format.flags & LLONG)
		cast = (long long)va_arg(*app, int);
	else if (format.flags & INTMAX)
		cast = (intmax_t)va_arg(*app, int);
	else if (format.flags & SIZE_T)
		cast = (size_t)va_arg(*app, int);
	else if (format.flags & PTRDIFF)
		cast = (ptrdiff_t)va_arg(*app, int);
	else
		cast = (int)va_arg(*app, int);
	return (cast);
}

/* void	print_itoa(intmax_t n, t_format format)
{
	char		n_buff[ITOA];
	uintmax_t	absolute_n;
	int32_t		char_printed;
	int32_t		padding;

	absolute_n = ft_absolute(n);
	char_printed = 0;
	while (absolute_n)
	{
		absolute_n /= 10;
		++char_printed;
	}
	if ((n < 0 || (format.flags & SIGN) || (format.flags & SPACE))
			&& (format.flags & ZERO_PAD))
		--(format.precision);
	char_printed = ft_max(char_printed, format.precision);
	if (n < 0 || (format.flags & SIGN) || (format.flags & SPACE))
		++char_printed;
	padding = (char_printed > format.width) ? 0 : format.width - char_printed;
	padd_value(format, PAD_LEFT, padding);
	absolute_n = ft_absolute(n);
	itoa_base(absolute_n, 10, n_buff, p);
	(format.flags & SPACE) ? n_buff[0] = ' ' : 0;
	(n < 0) ? n_buff[0] = '-' : 0;
	(format.flags & SIGN && n >= 0) ? s[0] = '+' : 0;
	buffered_print(n_buff, char_printed);
	padd_value(format, PAD_RIGHT, padding);
}
 */
