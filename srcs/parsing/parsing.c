/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 23:36:54 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/29 20:57:11 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "printing.h"
// DEBUG
#include "print_test.h"

 static void	init_format(t_format *format)
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
	// print_test(format);
	print_arg(format, app, buffer);
	return (++str);
}
