/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:36:54 by cbaillat          #+#    #+#             */
/*   Updated: 2018/01/08 15:27:13 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "printing.h"

static void	init_format(t_format *format)
{
	format->flags = 0;
	format->width = 0;
	format->precision = 1;
	format->to_print = 0;
	format->specifier = '\0';
}

/*
** Returns a pointer to the character after the format, or after what has
** already been printed.
*/

char		*parse_format(char *str, va_list *app, t_buffer *buffer)
{
	t_format	format;

	init_format(&format);
	while (42)
	{
		if (seek_flag(&str, &format) == SUCCESS)
			continue ;
		if (seek_width(&str, &format, app) == SUCCESS)
			continue ;
		if (seek_precision(&str, &format, app) == SUCCESS)
			continue ;
		if (seek_length(&str, &format) == SUCCESS)
			continue ;
		break ;
	}
	get_specifier(&str, &format);
	print_arg(format, app, buffer);
	return (str);
}
