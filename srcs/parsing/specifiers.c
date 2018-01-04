/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:06 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/04 16:03:41 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** SPECIFIERS:
** d,i	Signed decimal integer								| 392
** u	Unsigned decimal integer							| 7235
** o	Unsigned octal										| 610
** D,O,U are equivalent to ld, lo, lu
** x	Unsigned hexadecimal integer						| 7fa
** X	Unsigned hexadecimal integer (uppercase)			| 7FA
** f	Decimal floating point, lowercase					| 392.65
** F	Decimal floating point, uppercase					| 392.65
** e	Scientific notation (mantissa/exponent), lowercase	| 3.9265e+2
** E	Scientific notation (mantissa/exponent), uppercase	| 3.9265E+2
** g	Use the shortest representation: %e or %f			| 392.65
** G	Use the shortest representation: %E or %F			| 392.65
** a	Hexadecimal floating point, lowercase				| -0xc.90fep-2
** A	Hexadecimal floating point, uppercase				| -0XC.90FEP-2
** c	Character											| a
** s	String of characters								| sample
** p	Pointer address										| b8000000
** n	argument must be a ptr to an int. number of char written is
**		stored in the pointed location.
** %	A % followed by another % character will write a single % to the stream
*/

/*
** Either returns NULL if the specifier is found
** or the pointer to which the string should continue to be parsed if no
** specifier is found
**
** 1- We check if there actually is a specifier. If we can't find one, we print
** all the preceding arguments as if they were a string, and return a pointer
** to the end of that bit, so that we can continue parsing the string.
** 2- If we find an uppercase letter, we set the corresponding flag and put the
** letter in lowercase.
*/

static void	set_upper_flag(char *c, t_format *format)
{
	if (ft_strchr("DUOCS", *c) != NULL)
		format->flags |= LONG;
	if (ft_strchr("XFEGA", *c) != NULL)
		format->flags |= UPPERCASE;
}

static char	*undefined_behaviour(char *string, va_list *app, t_buffer *buffer)
{
	char	*formatting;

	formatting = "-+ #.*0hijlLtz";
	if (ft_strchr(formatting, *string) == NULL && !ft_isdigit(*string))
	{
		buffered_print("% ", 0, buffer);
		va_arg(*app, int);
		buffer->undefined_behaviour = UNDEFINED_BEHAVIOUR;
		return (string + 1);
	}
	return (string);
}

char	*get_specifier(char *string, t_format *format, va_list *app,
			t_buffer *buffer)
{
	char	*traverse;
	char	*specifier;

	specifier = "dDiuUboOxXfFeEgGaAcCsSpn%";
	traverse = string;
	while (*traverse != '\0')
	{
		if (ft_strchr(specifier, *traverse) != NULL)
		{
			if (ft_isupper(*traverse))
				set_upper_flag(traverse, format);
			format->specifier = *traverse;
			return (NULL);
		}
		else
			traverse = undefined_behaviour(traverse, app, buffer);
		++traverse;
	}
	return (traverse);
}
