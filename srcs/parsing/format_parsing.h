/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:31 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 19:24:17 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PARSING_H
#define FORMAT_PARSING_H

#include "ft_printf.h"

/*
** The following enums will help to make the code cleaner
*/

typedef enum {
	minus = 0,
	plus,
	space,
	pound,
	zero,
	flag_unknown
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
	length_unknown
}				e_length;

typedef enum {
	integer = 0,
	floating_point,
	string,
	void_ptr,
	int_ptr,
	type_unknown
}				e_sp_type;

typedef struct	s_flag
{
	e_flag			flag;
	struct s_flag	*next;
}				t_flag;

typedef struct	s_format
{
	t_flag		*flag;
	int32_t		width;
	int32_t		precision;
	int8_t		uppercase;
	e_length	length;
	e_sp_type	type;
	char		specifier;
}				t_fkormat;

char			*get_specifier(char *string, t_format *format);
e_sp_type		get_type(char specifier);
char			*parse_format(char *str, va_list *app);
int32_t			search_flag(t_flag *list, e_flag flag);
int32_t			seek_flag(char **string, t_format *format);
int32_t			seek_length(char **string, t_format *format);
int32_t			seek_precision(char **string, t_format *format, va_list *app);
int32_t			seek_width(char **string, t_format *format, va_list *app);

#endif
