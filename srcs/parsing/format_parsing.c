/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 19:46:22 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"
#include "arg_print.h"
// DEBUG
#include "print_test.h"

static void	init_format(t_format *format)
{
	format->flag = NULL;
	format->width = 0;
	format->precision = 1;
	format->length = length_unknown;
	format->uppercase = LOWERCASE;
	format->type = type_unknown;
	format->specifier = '\0';
}


/*
** Returns a pointer to the character after the format, or after what has
** already been printed.
*/

#include <stdio.h>
char	*parse_format(char *str, va_list *app)
{
	char		*ret;
	t_format	format;

	init_format(&format);
	ret = get_specifier(str, &format);
	if (ret != NULL)
		return (ret);
	while (*str != format.specifier)
	{
		seek_flag(&str, &format);
		seek_width(&str, &format, app);
		seek_precision(&str, &format, app);
		seek_length(&str, &format);
	}
	print_test(format);
	return (++str);
}
