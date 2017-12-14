/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 09:46:29 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/14 13:56:12 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int32_t is_sp_integer(char c)
{
	const char *sp_integer;
	const char *sp_ptr;

	sp_integer = "dDioOuUxX";
	sp_ptr = sp_integer;
	while (*sp_ptr != '\0')
	{
		if (*sp_ptr == c)
			return (sp_ptr - sp_integer);
		++sp_ptr;
	}
	return (FAILURE);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	char *  tmp;
	int32_t sp_type;

	tmp = format;
	va_start(ap, format);
	while (tmp != '\0')
	{
		if (tmp != '%')
		{
			ft_putchar(tmp);
			continue;
		}
		if ((sp_type = is_sp_integer(++tmp)) != FAILURE)
			; // parse_flag(sp_type);
			  // continue checking the type of the specifier
	}
	va_end(ap);
	return (SUCCESS);
}
