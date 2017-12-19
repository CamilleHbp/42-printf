/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:28:32 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/19 17:15:29 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_print.h"


int32_t		print_arg(t_format format, va_list *app)
{
	if (format.specifier == "di")
		print_integer(format, *app));
	else if (format.specifier == "f")
		print_float(format, *app));
	else if (format.specifier == "oubxX")
		print_base(format, *app));
	else if (format.specifier == "cC")
		print_char(format, *app));
	else if (format.specifier == "s")
		print_string(format, *app));
	else if (format.specifier == "S")
		print_wstring(format, *app));
	else if (format.specifier == "p")
		print_pointer(format, *app));
	else if (format.specifier == "n")
		return_written_char(format, *app));

}
