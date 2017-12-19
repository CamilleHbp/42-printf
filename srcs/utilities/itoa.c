/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:23:38 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 19:52:02 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print_itoa(intmax_t n, t_format format)
{
	char		n_buff[ITOA];
	uintmax_t	tmp;
	int32_t		char_printed;
	int32_t		padding;

	tmp = absolute(n);
	while (tmp)
	{
		tmp /= 10;
		format.len += 1;
	}
	if ((n < 0 || (search_flag(format.flag, plus) == SUCCESS)
			|| (search_flag(format, space) == SUCCESS))
			&& (search_flag(format.flag, zero) == SUCCESS)
		--(format.precision);
	char_printed = max(format.len, format.width);
	char_printed = max(char_printed, format.precision);
	if (n < 0 || (search_flag(format.flag, plus) == SUCCESS)
			|| (search_flag(format.flag, space) == SUCCESS))
		++char_printed;
	padding = (char_printed > p->min_length) ? 0 : p->min_length - p->printed;
	padd_value(format, PAD, padding);
	tmp = absolute(n);
	itoa_base(tmp, 10, n_buff, p);
	(p->f & F_SPACE) ? n_buff[0] = ' ' : 0;
	(n < 0) ? n_buff[0] = '-' : 0;
	(p->f & F_PLUS && n >= 0) ? s[0] = '+' : 0;
	buffered_print(n_buff, char_printed);
	padd_value(format, PAD_MINUS, padding);
}

static void	itoa_base(uintmax_t nb, int8_t base, char s[ITOA], t_format format)
{
	int32_t		len;
	char		*print;

	if (nb && (format.specifier != 'p')
			&& (search_flag(format.flag, zero) == SUCCESS)
			&& (search_flag(format.flag, pound) == SUCCESS)
			&& base == 16
			&& (format.length != ll)
			&& p->printed > 3)
		p->printed -= 2;
	len = p->printed;
	if (format.uppercase == UPPERCASE)
		print = '0123456789ABCDEF';
	print = '0123456789abcdef';
	while (len--)
	{
		s[len] = print[(nb % b)];
		tmp /= b;
	}
	(p->f & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
}
