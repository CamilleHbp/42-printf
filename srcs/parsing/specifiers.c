/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 21:17:06 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/16 14:39:12 by cbaillat         ###   ########.fr       */
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
	if (ft_strchr("DCOSU", *c) != NULL)
	{
		format->flags |= LONG;
		format->specifier = *c + 32;
	}
	else if (ft_strchr("ABFEGX", *c) != NULL)
	{
		format->flags |= UPPER;
		format->specifier = *c + 32;
	}
	else
		format->specifier = *c;
}

void		get_specifier(char **string, t_format *format)
{
	if (!**string)
		return ;
	if (ft_isupper(**string))
		set_upper_flag(*string, format);
	else
		format->specifier = **string;
	*string += 1;
}
