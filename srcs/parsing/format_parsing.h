/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:31 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/15 23:29:49 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PARSING_H
#define FORMAT_PARSING_H

#include "ft_printf.h"



/* WIDTH:
** (nb)	Minimum number of characters to be printed. If the value to be
**		printed is shorter than this number, the result is padded with blank
**		spaces. The value is not truncated even if the result is larger.
** *	The width is not specified in the format string, but as an
**		additional integer value argument preceding the argument that has
**		to be formatted.
*/

/* PRECISION:
** .number	dDioOuUxX:
**		precision specifies the minimum number of digits to be written.
**		If the value is shorter, the result is padded with leading zeros.
**		The value is not truncated even if the result is longer.
**		A precision of 0 means that no character is written for the value 0.
**			aAeEfFgG:
**		number of digits to be printed after the decimal point (default is 6).
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

/*
** The following enums will help to make the code cleaner
*/

typedef enum {
	minus = 0,
	plus,
	space,
	pound,
	zero,
	none
}				e_flag;

typedef enum {
	h = 0,
	l,
	j,
	z,
	t,
	L,
	hh,
	ll,
	unknown
}				e_length;

typedef enum {
	integer = 0,
	floating_point,
	string,
	void_ptr,
	int_ptr,
	unknown
}				e_sp_type;

typedef struct	s_flag
{
	e_flag	flag;
	t_flag	*next_flag;
}				t_flag;

typedef struct	s_format
{
	t_flag		*flag;
	t_bool		width_flag;
	uint32_t	width;
	uint32_t	precision;
	e_length	length;
	e_sp_type	type;
	char		specifier;
}				t_format;

char			*get_specifier(const char *string, t_format *format);
e_sp_type		get_type(const char specifier);
int32_t			seek_flag(const char *string, t_format *format);
t_bool			seek_length(const char **string, t_format *format);
t_bool			seek_width(const char **string, t_format *format);

#endif
