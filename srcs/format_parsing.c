/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/14 14:46:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

int32_t	seek_flag(const char *string, uint32_t index)
{
	char	*flag;
	char	*found;

	flag = "-+ #0";
	if (string[index] == '0' && is_digit(string[index - 1]))
		return (FAILURE);
	if ((found = ft_strchr(flag, string[index])) != NULL)
		return (found - flag);
	return (FAILURE);
}

const char *seek_width(const char *format, int *int_queue)
{
	*int_queue = 0;
	if (*format == '*')
	{
		format++;
		(*int_queue)++;
	}
	else
	{
		while (ft_isdigit((unsigned char)*format))
			format++;
	}
	if (*format == '.')
	{
		if (*format == '*')
		{
			format++;
			(*int_queue)++;
		}
		else
		{
			while (ft_isdigit((unsigned char)*format))
				format++;
		}
	}
	return format;
}

const char *seek_mod(const char *format, int *mod)
{
	*mod = 0;
	if (format[0] == 'h' && format[1] == 'h')
	{
		format += 2;
	}
	else if (format[0] == 'l' && format[1] == 'l')
	{
		*mod = ('l' << CHAR_BIT) + 'l';
		format += 2;
	}
	else if (ft_strchr("ljztL", *format))
	{
		*mod = *format;
		format++;
	}
	else if (ft_strchr("h", *format))
	{
		format++;
	}
	return format;
}

const char *seek_specifier(const char *format, int mod, e_specifier *specifier)
{
	if (ft_strchr("dDioOuUxX", *format))
	{
		*specifier = integer;
		format++;
	}
	else if (ft_strchr("fFeEgGaA", *format))
	{
		if (mod == 'l')
			mod = 0;
		*type = type_float;
		format++;
	}
	else if (ft_strchr("c", *format))
	{
		*type = type_int;
		format++;
	}
	else if (ft_strchr("s", *format))
	{
		*type = type_charpointer;
		format++;
	}
	else if (strchr("p", *format))
	{
		*type = type_voidpointer;
		format++;
	}
	else if (strchr("n", *format))
	{
		*type = type_intpointer;
		format++;
	}
	else
	{
		*type = type_unknown;
		exit(1);
	}
	*type |= mod << CHAR_BIT; // Bring in modifier
	return format;
}

v

	// 0 Compatible
	// 1 Not Compatible
	// 2 Not Comparable
	int
	format_cmp(const char *f1, const char *f2)
{
	format_T state1;
	format_init(&state1, f1);
	format_T state2;
	format_init(&state2, f2);
	while (format_get(&state1) == format_get(&state2))
	{
		if (format_get(&state1) == type_none)
			return 0;
		if (format_get(&state1) == type_unknown)
			return 2;
		format_next(&state1);
		format_next(&state2);
	}
	if (format_get(&state1) == type_unknown)
		return 2;
	if (format_get(&state2) == type_unknown)
		return 2;
	return 1;
}
