/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:46:29 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 20:24:33 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*tmp;

	tmp = (char *)format;
	va_start(ap, format);
	while (*tmp != '\0')
	{
		if (*tmp == '%')
			tmp = parse_format(tmp + 1, &ap);
		else
		{
			ft_putchar(*tmp);
			++tmp;
		}
	}
	va_end(ap);
	return (SUCCESS);
}
