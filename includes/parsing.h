/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:37:13 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/20 23:37:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_PARSING_H
# define FORMAT_PARSING_H

# include "ft_printf.h"
#include "utils.h"

/*
** The following flags are used thourought the code and stored in an int32.
** All the flags are stored as single bits. It is faster when checking, and does
** not require as much memory (secondary to the first reason).
*/

# define RIGHT_PAD	(1 << 0)
# define SIGN		(1 << 1)
# define PREFIX		(1 << 2)
# define SPACE		(1 << 3)
# define ZERO_PAD	(1 << 4)

# define UPPERCASE	(1 << 5)
# define UNICODE	(1 << 6)

# define SHORT		(1 << 7)
# define SSHORT		(1 << 8)
# define LONG		(1 << 9)
# define LLONG		(1 << 10)
# define INTMAX		(1 << 11)
# define SIZE_T		(1 << 12)
# define PTRDIFF	(1 << 13)
# define LDOUBLE	(1 << 14)

# define MIN_LEN	(1 << 15)
# define APP_PRECI	(1 << 16)
# define POINTER	(1 << 17)

/*
** This little macro does not execute code. It is simply here to remember that
** by ANDing with the complement of the flag, I actually unset the flag.
*/

typedef struct	s_format
{
	uint32_t	flags;
	int32_t		width;
	int32_t		precision;
	char		specifier;
}				t_format;

char			*get_specifier(char *string, t_format *format);
char			*parse_format(char *str, va_list *app);
int32_t			seek_flag(char **string, t_format *format);
int32_t			seek_length(char **string, t_format *format);
int32_t			seek_precision(char **string, t_format *format, va_list *app);
int32_t			seek_width(char **string, t_format *format, va_list *app);

#endif
