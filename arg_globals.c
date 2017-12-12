/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_globals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:48:27 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/12 19:06:05 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	g_flags[] = {
	'-',	//left-justify
	'+',	//force '+' (even if positive) or '-'
	' ',	//prints ' ' if not sign is written
	'#',	//'o,O,x,X': preceded by 0, 0x, 0X. 'a,A,e,E,f,F,g,G': force deci'.'
	'0',	//leftpad with '0' instead of ' '
	'\0'
};
const char	g_width = '*';	//width is the integer arg preceding this.
const char	g_prec = '.';		//'d,i,o,x': min nb of digits to write
									//'a,e,f: nnb of digits after the '.'
									//'g' max nb of significant digits
									//'s' max number of char to print
									// nothing after '.' means '0'
									//'*' is the integer arg preceding this.
const char	g_length[] = {
	//none	  d,i: int   | u,o,x: uint   | f,e,g,a: double | c: int | n: int*
	'hh',	//d,i: char  | u,o,x: uchar  | n: char*
	'h',	//d,i: short | u,o,x: ushort | n: short*
	'l',	//d,i: long  | u,o,x: ulong  | c:wint_t | s: wchar_t* | n: long*
	'll',	//d,i: long long | u,o,x: ulong long | n: long long*
	'j',	//d,i: intmax_t  | u,o,x: uintmax_t  | n: intmax_t*
	'z',	//d,i: size_t | u,o,x: size_t | n: size_t*
	//'t',	//d,i: ptrdiff_t | u,o,x: ptrdiff_t | n: ptrdiff_t*
	//'L',	//f,e,g,a: long double
	'\0'
};
const char	g_sp_integer[] = {
	'd',	//signed decimal int
	'D',
	'i',	//signed decimal int
	'o',	//unsigned octal
	'O',
	'u',	//unsigned decimal int
	'U',
	'x',	//unsigned hex int
	'X',	//unsigned hex int (uppercase)
	'\0'
};
const char	g_sp_char[] = {
	's',	//string
	'S',
	'c',	//character
	'C',
	'\0'
};
const char	g_sp_float[] = {
	'f',	//decimal float (lowercase)
	'f',	//decimal float (uppercase)
	'e',	//scientific notation (lowercase)
	'E',	//scientific notation (uppercase)
	'g',	//shortest: %e or %f
	'G',	//shortest: %E or %F
	'a',	//hexadecimal floating point (lowercase)
	'A',	//hexadecimal floating point (uppercase)
	'\0'
};
const char	g_sp_special[] = {
	'p',	//pointer address. arg is void *
	'n',	//arg should be a pointer to int. stores number of char written
	'\0'
};
