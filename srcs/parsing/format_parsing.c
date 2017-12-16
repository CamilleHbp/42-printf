/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:04:50 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/16 17:19:56 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_parsing.h"

const char *seek_width(const char *format, int *int_queue)
{
	*int_queue = 0;
	if (*format == '*')
	{
		format++;
		(*int_queue)++;
	}
	else
	{
		while (ft_isdigit((unsigned char)*format))
			format++;
	}
	if (*format == '.')
	{
		if (*format == '*')
		{
			format++;
			(*int_queue)++;
		}
		else
		{
			while (ft_isdigit((unsigned char)*format))
				format++;
		}
	}
	return format;
}

static void	init_format(t_format *format)
{
	format->flag = NULL;
	format->width_flag = 0;
	format->width = 0;
	format->preci_flag = 0;
	format->precision = 0;
	format->length = unknown;
	format->type = unknown;
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
		if (seek_flag(str, &format) == SUCCESS)
			;
		else if (seek_width(str, &format) == SUCCESS)
			;
		else if (seek_precision(str, &format) == SUCCESS)
			;
		else if (seek_length(&str, &format) == SUCCESS)
			;
		++str;
	}
	print_arg(&format, *app);
	return (++str);
}
