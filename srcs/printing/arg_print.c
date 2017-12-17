/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 22:28:32 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/17 21:44:03 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg_print.h"

// static int32_t		print_integer(t_format format, __int128_t integer)
// {
	// ;
// }

int32_t		print_arg(t_format format, va_list *app)
{
	if (format.specifier == "diu")
		print_integer(format, *app));
	else if (format.specifier == "f")
		print_float(format, *app));
	else if (format.specifier == "oOuUbUxX")
		print_base(format, *app));
}
