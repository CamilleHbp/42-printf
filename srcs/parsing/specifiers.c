/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:06 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 13:03:14 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

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
** We get the type of specifier to know how to interpret the different flags and
** modifiers.
*/

e_sp_type	get_type(char specifier)
{
	if (ft_strchr("dDioOuUxX", specifier))
		return (integer);
	else if (ft_strchr("fFeEgGaA", specifier))
		return (floating_point);
	else if (ft_strchr("cCsS", specifier))
		return (string);
	else if (ft_strchr("p", specifier))
		return (void_ptr);
	else if (ft_strchr("n", specifier))
		return (int_ptr);
	return (type_unknown);
}

/*
** Either returns NULL if the specifier is found
** or the pointer to which the string should continue to be parsed if no
** specifier is found
*/

char	*get_specifier(char *string, t_format *format)
{
	char		*traverse;
	char		*specifier;

	specifier = "dDiuUoOxXfFeEgGaAcCsSpn%";
	traverse = string;
	while (42)
	{
		if (*traverse == '\0' || *traverse == ' ')
		{
			ft_putnstr(string, (traverse - string));
			return (traverse);
		}
		if (ft_strchr(specifier, *traverse) != NULL)
		{
			if (ft_strchr("DUO", *traverse) != NULL)
			{
				format->length = l;
				*traverse += 32;
			}
			format->specifier = *traverse;
			format->type = get_type(*traverse);
			return (NULL);
		}
		++traverse;
	}
	return (NULL);
}
