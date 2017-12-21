/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:33:22 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/20 23:33:22 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

void	itoa_base(uintmax_t nb, int8_t base, char s[ITOA], t_format format)
{
	int32_t		len;
	char		*print;

	if (nb && (format.specifier != 'p')
			&& (format.flags & ZERO_PAD)
			&& (format.flags & PREFIX)
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
		absolute_n /= b;
	}
	(format.flags & F_APP_PRECI && p->f & F_ZERO) ? s[0] = ' ' : 0;
}

static void	print_prefix(intmax_t nb, uint8_t base, char *prefix, t_format *format)
{
	if (base == 10)
	{
		if (nb < 0)
			buffered_print('-', 1);
		else if ((format.flags & SIGN))
			buffered_print('+', 1);
		else if ((format.flags & BLANK))
			buffered_print(' ', 1);
	}
	else if (nb != 0)
	{
		if (format.flags & PREFIX)
			buffered_print(prefix, 1);
	}
}

void	print_number(intmax_t nb, uint8_t base, char *prefix, t_format *format)
{
	char	*nb_str[NB_STR_MAX];
	size_t	nb_len;
	size_t	leftover;

	// first we need to calculate the total width needed
	if ((nb < 0) || (format.flags & SIGN) || (format.flags & BLANK))
		format.width -= 1;
	nb_len = get_nb_len(nb, base);
	format.width -= ((format.flags & ZERO_PAD) ? 0 : ft_strlen(prefix));
	format.width -= ft_max(format.precision, nb_len);

	// If we need to right justify, we pad on the left with spaces or 0
	if (!(format.flags & RIGHT_PAD) && (format.flags & ZERO_PAD))
		padd_value('0', format.width);
	else if (!(format.flags & RIGHT_PAD))
		padd_value(' ', format.width);
	// if the number is 0 and we have a precision of 0, we only need to pad
	if (nb == 0 && (format->precision == 0))
		return ;
	print_prefix(nb, base, prefix, format);
	// We print the necessary 0 padding
	leftover = format->precision - nb_len;
	while (leftover > 0)
		padd_value('0', nb_display_len);
	atoi_base(ft_absolute(nb), base);
	if (format.flags & RIGHT_PAD)
		padd_value(' ', format.width);
}
ssize_t	prefix_management(uintmax_t nbr, uint8_t base, t_format *format, char *prefix)
{
	unsigned	nbr_len;
	size_t		nbr_cut;

	nbr_len = get_nb_display_len(nbr, base, NULL, arg) + ft_strlen(prefix);
	nbr_cut = ft_strlen(prefix);
	if ((format.width) && !(format.flags & RIGHT_PAD) && !(format.flags && ZERO_PAD))
	{
		padd_value(nbr_len, arg->width, ' ');
		nbr_cut += ft_max(arg->width - nbr_len, 0);
		arg->got_width = 0;
	}
	else if (arg->got_width)
		arg->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (ft_printf_handle_uint(nbr, arg, base, NULL) + nbr_cut);
}
