/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:11:44 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 18:25:15 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printing.h"

static void	print_flags(t_format format)
{
	ft_putstr("flags :");
	if (format.flags & RIGHT_PAD)
		ft_putstr(" - ");
	if (format.flags & SIGN)
		ft_putstr(" + ");
	if (format.flags & PREFIX)
		ft_putstr(" # ");
	if (format.flags & SPACE)
		ft_putstr(" space ");
	if (format.flags & ZERO_PAD)
		ft_putstr(" 0 ");
	ft_putstr("\n");
}

static void	print_length(t_format format)
{
	ft_putstr("length: ");
	if (format.flags & SHORT)
		ft_putstr(" h ");
	if (format.flags & SSHORT)
		ft_putstr(" hh ");
	if (format.flags & LONG)
		ft_putstr(" l ");
	if (format.flags & LLONG)
		ft_putstr(" ll ");
	if (format.flags & INTMAX)
		ft_putstr(" j ");
	if (format.flags & SIZE_T)
		ft_putstr(" z ");
	if (format.flags & PTRDIFF)
		ft_putstr(" t ");
	if (format.flags & LDOUBLE)
		ft_putstr(" L ");
	ft_putstr("\n");
}

void	print_test(t_format format)
{
	ft_putstr("\n----------------\n");
	print_flags(format);
	ft_putstr("width: ");
	ft_putnbr(format.width);
	ft_putchar('\n');
	ft_putstr("precision: ");
	ft_putnbr(format.precision);
	ft_putchar('\n');
	print_length(format);
	ft_putstr("specifier: ");
	ft_putchar(format.specifier);
	ft_putchar('\n');
	ft_putstr("----------------\n");
}
