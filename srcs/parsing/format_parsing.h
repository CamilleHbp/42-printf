/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:31 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/16 17:19:35 by cbaillat         ###   ########.fr       */
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
	t_bool		preci_flag;
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
