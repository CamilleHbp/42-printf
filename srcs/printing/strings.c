/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaillat <cbaillat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:34:20 by cbaillat          #+#    #+#             */
/*   Updated: 2017/12/26 20:33:32 by cbaillat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "printing.h"

ssize_t	print_string(t_format format, va_list *app)
{
	char	*str;
	size_t	len;
	size_t	width;

	if (format.flags & UNICODE)
		return (print_wstr(format, app));
	str = va_arg(*args, char*);
	if (str == NULL)
		return (0);
	if (format.flags & UNICODE)
		len = (format.flags & PRECISION) ? format.precision : ft_wstrlen(str);
	else
		len = (format.flags & PRECISION) ? format.precision : ft_strlen(str);
	width = (format.width - len > 0) ? format.width - len : len;
	if (!(format.flags & RIGHT_PAD)
		padd_value((format.flags & ZERO_PAD) ? '0' : ' ', width);
	if (format.flags & UNICODE)
		buffer_wstring(str, len);
	else
		buffered_print(str, len);
	if (format.flags & RIGHT_PAD)
		padd_value(' ', width);
	return ((format.width > len) ? format.width : len);
}
