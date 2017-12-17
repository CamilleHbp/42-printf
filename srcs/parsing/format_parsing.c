/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 13:23:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"
#include "arg_print.h"
// DEBUG
#include "print_test.h"

static void	init_format(t_format *format)
{
	format->flag = NULL;
	format->width_flag = 0;
	format->width = 0;
	format->preci_flag = 0;
	format->precision = 0;
	format->length = length_unknown;
	format->type = type_unknown;
	format->specifier = '\0';
}


/*
** Returns a pointer to the character after the format, or after what has
** already been printed.
*/

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
		if (seek_flag(&str, &format) == SUCCESS)
			{;}
		else if (seek_width(&str, &format) == SUCCESS)
			{;}
		else if (seek_precision(&str, &format) == SUCCESS)
			{;}
		else if (seek_length(&str, &format) == SUCCESS)
			{;}
		++str;
	}
	print_test(format, app);
	return (++str);
}
