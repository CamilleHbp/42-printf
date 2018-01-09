/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 09:34:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/09 14:29:00 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_itoa_base(uintmax_t nb, int8_t base, t_format format,
					 char nb_str[ITOA])
{
	int32_t tmp;
	char *  print;

	if (format.flags & UPPERCASE)

		print = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		print = "0123456789abcdefghijklmnopqrstuvwxyz";
	tmp = format.to_print;
	while (tmp--)
	{
		nb_str[tmp] = print[(nb % base)];
		nb /= base;
	}
}

static void	return_nb_str(char nb_str[ITOA], size_t len, uintmax_t nb,
						  int8_t base, t_format format)
{
	char *print;

	if (format.flags & UPPERCASE)
		print = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		print = "0123456789abcdefghijklmnopqrstuvwxyz";
	while (len--)
	{
		nb_str[len] = print[(nb % base)];
		nb /= base;
	}
}

void		buffer_itoa_base(uintmax_t nb, int8_t base, t_format format,
					  t_buffer *buffer)
{
	uintmax_t tmp;
	size_t	len;
	char	  nb_str[ITOA];

	len = 1;
	tmp = ITOA;
	while (tmp-- > 0)
		nb_str[tmp] = 0;
	tmp = nb;
	while ((tmp /= base) > 0)
		++len;
	if ((nb == 0) && ((format.flags & PRECISION) && (format.precision == 0)))
		nb_str[0] = '\0';
	else if (nb == 0)
		nb_str[0] = '0';
	else
		return_nb_str(nb_str, len, nb, base, format);
	buffered_print(nb_str, ft_strlen(nb_str), buffer);
}
