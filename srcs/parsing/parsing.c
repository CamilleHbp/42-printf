/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:36:54 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/03 19:29:54 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "printing.h"

static void init_format(t_format *format)
{
	format->flags = 0;
	format->width = 0;
	format->precision = 1;
	format->specifier = '\0';
}

/*
** Returns a pointer to the character after the format, or after what has
** already been printed.
*/

char	*parse_format(char *str, va_list *app, t_buffer *buffer)
{
	char *   ret;
	t_format format;

	init_format(&format);
	ret = get_specifier(str, &format, app, buffer);
	if (ret != NULL)
		return (ret);
	while (*str != format.specifier)
	{
		if (seek_flag(&str, &format) == SUCCESS)
			continue;
		seek_width(&str, &format, app);
		seek_precision(&str, &format, app);
		seek_length(&str, &format);
	}
	// print_test(format);
	print_arg(format, app, buffer);
	return (++str);
}
