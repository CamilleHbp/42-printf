/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_itoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 09:34:33 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/08 16:56:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		print_itoa_base(uintmax_t nb, int8_t base, t_format format,
			t_buffer *buffer)
{
	int32_t	tmp;
	char	nb_str[ITOA];
	char	*print;

	if (format.flags & UPPERCASE)
		print = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		print = "0123456789abcdefghijklmnopqrstuvwxyz";
	tmp = format.to_print;
	while (tmp--)
	{
		nb_str[tmp] = print[(nb % base)];
		nb /= base;
	// DEBUG:
	ft_putstr("NB STR: ");
	ft_putchar(nb_str[tmp]);
	ft_putstr("\n");
	}
	buffered_print(nb_str, format.to_print, buffer);
 }
