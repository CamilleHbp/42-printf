/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:08:03 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/14 13:02:47 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_LIST_H
#define FORMAT_LIST_H

#include "format_parsing.h"

/*
** FLAGS:
** -	Left-justify within the given field width; Right justification is the
**		default (see width sub-specifier).
** +	Forces to preceed the result with a plus or minus sign (+ or -) even for
**		positive numbers. By default, only negative numbers have a - sign.
** (space)	If no sign is going to be written, a blank space is inserted before
**		the value.
** #		o,x,X:
**		value is preceeded with 0, 0x or 0X for values different than zero.
**			a,A,e,E,f,F,g,G:
**		it forces the output to contain a decimal point even if no digits follow.
**		By default, if no digits follow, no decimal point is written.
** 0	Left-pads the number with zeroes (0) instead when padding is specified
*/

/* WIDTH:
** (nb)	Minimum number of characters to be printed. If the value to be
**		printed is shorter than this number, the result is padded with blank
**		spaces. The value is not truncated even if the result is larger.
** *	The width is not specified in the format string, but as an
**		additional integer value argument preceding the argument that has
**		to be formatted.
*/

/* PRECISION:
** .number	d,D,i,o,O,u,U,x,X:
**		precision specifies the minimum number of digits to be written.
**		If the value is shorter, the result is padded with leading zeros.
**		The value is not truncated even if the result is longer.
**		A precision of 0 means that no character is written for the value 0.
**			a,A,e,E,f,F:
**		number of digits to be printed after the decimal point (default is 6).
**			g,G:
**		This is the maximum number of significant digits to be printed.
**			s:
**		this is the maximum number of characters to be printed.
**		If the period is specified without an explicit value for precision,
**		0 is assumed.
** .*	The precision is not specified in the format string, but as an
**		additional integer value argument preceding the argument that has to be
**		formatted.
*/

/*
** LENGTH:
** As long as there is a flag, we keep looping and keep only the biggest flag
**	  | d,i			uoxX	fFeEgGaA	c		s		p		n
** -  |	int			uint	double		int		char*	void*	int*
** hh |	char		uchar										char*
** h  |	short 		ushort										short*
** l  |	long 		ulong 				wint_t	wchar_t*		long*
** ll |	long long	ulong long									long long*
** j  |	intmax_t	uintmax_t									intmax_t*
** z  |	size_t		size_t										size_t*
** t  |	ptrdiff_t	ptrdiff_t									ptrdiff_t*
** L  |						long double
*/

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

typedef struct
{
	int width;
} t_spec;

typedef struct
{
	e_flag
	int width;
} t_flag;

static typedef struct
{
	const char *format;
	int			int_queue;
	t_flag		*flag;
	uint32_t	width;
	uint32_t	precision;
	e_length	length;
	e_specifier spec;
} t_format;

#endif
